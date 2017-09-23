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


// Main Game loop
//
// # Arguments
//   int rounds : number of rounds to play the game
void Game::Play(int rounds, int8_t probability = 0) {
  
  for (int i = 0; i < rounds; i++) {
    Round(probability);
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


void Game::Round(int8_t probability)
{
  std::random_shuffle(population.begin(), population.end());
  const long num_pairs = population.size() / 2;

  Player *p1;
  Player *p2;
  
  // Random generator
  std::random_device rd;
  std::uniform_int_distribution<int> distribution(1, 100);
  std::mt19937 engine(rd()); // Mersenne twister MT19937
  
  // Make pairs
  std::vector<Player *>::iterator it = population.begin();
  for (int i = 0; i < num_pairs; i++) {
    
    p1 = *it++;
    p2 = *it++;

    int value = distribution(engine);
    
    bool reinteraction = false;
    while (!reinteraction) {
      p1->Move(p2);
      p2->Move(p1);
      
      reinteraction = (value > probability);
      value = distribution(engine);
    }
    
  }
  
}


void Game::generatePlayers(PlayerConfig *pc) {

  for (int i = 0; i < pc->titfortatcoop; ++i) {
    Player *pl = new Player;
    TitForTatCoop *st = new TitForTatCoop;
    pl->strategy = st;

    population.push_back(pl);
    
  }
  
  for (int i = 0; i < pc->titfortatdefect; ++i) {
    Player *pl = new Player;
    TitForTatDefect *st = new TitForTatDefect;
    pl->strategy = st;
    
    population.push_back(pl);
    
  }
  

    
}
