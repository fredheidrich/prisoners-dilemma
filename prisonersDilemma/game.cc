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




void Game::writeStats(std::string filename, Players* players, int round) {
  
  FILE* fout = fopen(filename.c_str(), "a");
  
  // header
  fprintf(fout, "Round\tPlayer\tScore\n");
  for (Players::const_iterator it = players->begin(); it != players->end(); ++it) {
    Player* p = static_cast<Player*>(*it);
    fprintf(fout, "%d\t%d\t%d\n", round, p->ID, p->score);
  }
  fclose(fout);
}


void Game::play(Players* players, int rounds, int probability) {
    
    // Random generator
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(1, 100);
    std::mt19937 engine(rd()); // Mersenne twister MT19937
    
    for (int i = 0; i < rounds; i++) {
        
        int value = distribution(engine);
        
        bool reinteraction = false;
        while (!reinteraction) {
            
            round(probability, players);
            
            reinteraction = (value <= probability);
            value = distribution(engine);
        }
      
      
      endRound(players);
      
      writeStats("test.tsv", players, i);
    }
  
  
//    PrintStats();
  
}


void Game::endRound(Players* players) {
  // end of the round
  players->reserve(players->size() * 2);
  int newborns = 0;
  
  for (std::vector<Player*>::iterator it = players->begin(); it != players->end();) {

      Player* p = static_cast<Player*>(*it);

      if (p->score < 0) {
        players->erase(it);
        delete *it;
      }else if (p->score > 100) {

        newborns += 1;
          Player *new_born = new Player(p->strat);

          int new_score = p->score / 2;
          p->score = new_score;
          new_born->score = new_score;
        
        players->push_back(p);
//        ++it;
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



// Main Game loop
//
// # Arguments
//   int rounds : number of rounds to play the game
void Game::Play(int rounds, int8_t probability = 0) {
  
  // Random generator
  std::random_device rd;
  std::uniform_int_distribution<int> distribution(1, 100);
  std::mt19937 engine(rd()); // Mersenne twister MT19937
  
  for (int i = 0; i < rounds; i++) {
    
    int value = distribution(engine);
    
    bool reinteraction = false;
    while (!reinteraction) {
    
      Round(probability);
      
      reinteraction = (value <= probability);
      value = distribution(engine);
    }
    
    // end of the round
    for (std::vector<Player*>::iterator it = this->population.begin(); it != population.end(); ++it) {
      
      Player* p = static_cast<Player*>(*it);
      
      if (p->score < 0) {
        population.erase(it);
      } else if (p->score > 100) {
       
        Player *pl = new Player;
        pl->strategy = p->strategy;
        
        int new_score = p->score / 2;
        p->score = new_score;
        pl->score = new_score;
        
      }
      
    }
    
    
  }
  
  PrintStats();
  
}


void Game::PrintStats() {
  std::vector<Player*>::iterator it;
  Player *p;
  
  for (it = population.begin(); it != population.end(); ++it) {
    p = *it;
    p->Print();
  }
}


void Game::round(int probability, Players* players)
{
  std::random_shuffle(players->begin(), players->end());
  
  for (std::vector<Player*>::iterator it = players->begin(); it != players->end(); ++it) {
    
      Player *p1 = nullptr;
      Player *p2 = nullptr;
    
    if ((it + 1) != players->end()) {
        p1 = static_cast<Player*>(*it);
        p2 = static_cast<Player*>(*(++it));  // next
      
        p1->move(*p2);
        p2->move(*p1);
        
    }
    
  }
  
}

void Game::Round(int8_t probability)
{
  std::random_shuffle(population.begin(), population.end());
//  const long num_pairs = population.size() / 2;

//  Player *p1;
//  Player *p2;
  
  // Make pairs
  ;
  for (std::vector<Player*>::iterator it = population.begin(); it != population.end(); ++it) {
    
    Player *p1 = static_cast<Player*>(*it);
//    p1 = *it++;
//    p2 = *it++;

//    p1->Move(p2);
//    p2->Move(p1);
  
  }
  
}


void Game::generatePlayers(PlayerConfig cfg, std::vector<Player*>& players) {
  
  for (int i = 0; i < cfg.titfortatcoop; ++i) {
    
    Player *pl = new Player(ttc);
  
    players.push_back(pl);
    
  }
  
}


void Game::generatePlayers(PlayerConfig pc) {

  for (int i = 0; i < pc.titfortatcoop; ++i) {
    Player *pl = new Player;
    TitForTatCoop *st = new TitForTatCoop;
    pl->strategy = st;

    population.push_back(pl);
    
  }
  
  for (int i = 0; i < pc.titfortatdefect; ++i) {
    Player *pl = new Player;
    TitForTatDefect *st = new TitForTatDefect;
    pl->strategy = st;
    
    population.push_back(pl);
    
  }
    
}
