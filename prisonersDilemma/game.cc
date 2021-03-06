//
//  Game.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include "game.h"

#include <iostream>
#include <random>

#include <cstdio>

// Number of players
PlayerConfig cfg = {
    .titfortatcoop = 8,
    .titfortatdefect = 4,
    .alldefect = 4,
    .allcooperate = 4,
    .random = 4,
};

// Parameters
int rounds = 100;
int8_t probability = 75;
int8_t crisisChance = 1;

int crisisPenalty = 0;
int endCrisis = 50;
bool lifeAndDeath = true;

// Settings
std::string filename = "file2.tsv";


// Global vars
bool inCrisis = false;
static void dump(std::vector<Player*> *players) {
  std::vector<Player*>::iterator it;
  Player *p;
  
  for (it = players->begin(); it != players->end(); ++it) {
    p = *it;
    p->Print();
  }
}

//#include <sys/stat.h>
//
//inline bool _exists (const std::string& name) {
//  struct stat buffer;
//  return (stat (name.c_str(), &buffer) == 0);
//}

static void writeHeader() {
  FILE* fout = fopen(filename.c_str(), "a");
  fprintf(fout, "====================\n");
    fprintf(fout, "ttc: %d\nttd: %d\ndef: %d\ncoop: %d\nRnd: %d\n",
          cfg.titfortatcoop,
          cfg.titfortatdefect,
          cfg.alldefect,
          cfg.allcooperate,
          cfg.random);
  fprintf(fout, "====================\n");
  fprintf(fout, "Round\tPlayer\tScore\tStrategy ID\tCrisis\n");
  fclose(fout);
}

void Game::writeStats(Players* players, int round) {
  
  FILE* fout = fopen(filename.c_str(), "a");
  
  // header
//  fprintf(fout, "Round\tPlayer\tScore\n");
  for (Players::iterator it = players->begin(); it != players->end(); ++it) {
    Player* p = static_cast<Player*>(*it);
    fprintf(fout, "%d\t%d\t%d\t%d\t%d\n", round, p->ID, p->score, p->strat, inCrisis);
//    std::cout << p->ID << " and " << p->score << "\n";
  }
  fclose(fout);
}


static void printPopulation(std::vector<Player*> *players) {
    
    int cttc = 0;
    int cttd = 0;
    int cdef = 0;
    int ccoop = 0;
    int crnd = 0;
    
    for (std::vector<Player*>::iterator it = players->begin(); it != players->end(); ++it) {
     
        switch (static_cast<Player*>(*it)->strat) {
            case ttc: cttc += 1; break;
            case ttd: cttd += 1; break;
            case def: cdef += 1; break;
            case coop: ccoop += 1; break;
            case rnd: crnd += 1; break;
        }
    }
    
    FILE* fout = fopen(filename.c_str(), "a");
    fprintf(fout, "====================\n");
    fprintf(fout, "ttc: %d\nttd: %d\ndef: %d\ncoop: %d\nRnd: %d\n",
            cttc,
            cttd,
            cdef,
            ccoop,
            crnd);
    fclose(fout);
        
}

void wipeMemory(Players *players) {
    for (std::vector<Player*>::iterator it = players->begin(); it != players->end(); ++it) {
        
        static_cast<Player*>(*it)->opponentsInteractionLastRound = NONE;
        static_cast<Player*>(*it)->myInteractionThisRound = NONE;
        
    }
}

void Game::play(Players* players) {
  
    
    writeHeader();
  
    // Random generator
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(1, 100);
    std::mt19937 engine(rd()); // Mersenne twister MT19937
    
    for (int i = 0; i < rounds; i++) {
        
        int value = distribution(engine);
        
        bool reinteraction = false;
        while (!reinteraction) {
            
            // shuffle players if this is not a reinteraction
            if (!reinteraction) {
                std::random_shuffle(players->begin(), players->end());
            }
            
            round(players);
            
            reinteraction = (value <= probability);
            value = distribution(engine);
        }
        
        if (inCrisis) {
            // chance to end crisis
            int crisis = distribution(engine);
            inCrisis = (crisis <= endCrisis);
        } else {
            // chance to start crisis
            int crisis = distribution(engine);
            inCrisis = (crisis <= crisisChance);
        }
      
      
        if (lifeAndDeath) {
            endRound(players);
        }
        
        wipeMemory(players);
      
      
      writeStats(players, i);
    }
  
    dump(players);
    printPopulation(players);
  
}


void Game::endRound(Players* players) {
  // end of the round
  players->reserve(players->size() * 2);
  int newborns = 0;
  
//  std::vector<Player**> graveyard;
  
  for (std::vector<Player*>::iterator it = players->begin(); it != players->end();) {

      Player* p = static_cast<Player*>(*it);
      
      if (p->score < 0) {
          delete *it;
          it = players->erase(it);
      } else if (p->score > 100) {

          newborns += 1;
          Player *new_born = new Player(p->strat);

          int new_score = p->score / 2;
          p->score = new_score;
          new_born->score = new_score;
        
        players->push_back(new_born);
      } else {
        ++it;
      }

  }
  if (newborns > 0) {
    Players::const_iterator start = players->begin();
    Players::const_iterator end = players->end() + newborns;
    std::vector<Player*> sub(start, end);
    players = &sub;
  }
}


void Game::round(Players* players)
{
    // shuffle players
//    std::random_shuffle(players->begin(), players->end());
  
    for (std::vector<Player*>::iterator it = players->begin(); it != players->end(); ++it) {
    
        Player *p1 = nullptr;
        Player *p2 = nullptr;
    
        if ((it + 1) != players->end()) {
            // cast reference to players
            // two and two
            p1 = static_cast<Player*>(*it);
            p2 = static_cast<Player*>(*(++it));  // next player
      
            p1->move(*p2);
            p2->move(*p1);
        
            // set memory
            if (p1->myInteractionThisRound == DEFECT) {
                p2->opponentsInteractionLastRound = DEFECT;
            } else {
                p2->opponentsInteractionLastRound = COOPERATE;
            }
        
            if (p2->myInteractionThisRound == DEFECT) {
                p1->opponentsInteractionLastRound = DEFECT;
            } else {
                p1->opponentsInteractionLastRound = COOPERATE;
            }
        
            // apply penalty if we are in crisis
            if (inCrisis) {
                p1->score -= crisisPenalty;
                p2->score -= crisisPenalty;
            }
        
        }
    
    }
  
}



void Game::generatePlayers(std::vector<Player*>& players) {
  
  for (int i = 0; i < cfg.titfortatcoop; ++i) {
    Player *pl = new Player(ttc);
    players.push_back(pl);
    
  }
  
  for (int i = 0; i < cfg.titfortatdefect; ++i) {
    Player *pl = new Player(ttd);
    players.push_back(pl);
  }
  
  for (int i = 0; i < cfg.alldefect; ++i) {
    Player *pl = new Player(def);
    players.push_back(pl);
  }
  
  for (int i = 0; i < cfg.allcooperate; ++i) {
    Player *pl = new Player(coop);
    players.push_back(pl);
  }
    
    for (int i = 0; i < cfg.random; ++i) {
        Player *pl = new Player(rnd);
        players.push_back(pl);
    }
  
}


