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
  
  for (int i = 0; i < rounds; i++)
  {
      
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
  
  // make pairs
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





//Game::Pair *Game::generatePairs() {

//  const long num_pairs = population.size() / 2;
//  Game::Pair *pairs = new Pair[num_pairs];
//  
////  std::vector<Game::Pair_t*> *pairs = new std::vector<Game::Pair_t*>;
////  std::vector<Game::Pair_t> pairs;
//  
//  std::random_shuffle(population.begin(), population.end());
//
//  
//  std::vector<Player *>::iterator it = population.begin();
//  for (int i = 0; i < num_pairs; it++) {
//    
//    Pair *p = new Pair;
//
//    p->p1 = *it;
//    p->p2 = *it++;
//    pairs[i] = p;
//  }
//
//  for (Game::Pair *p: pairs) {
//    std::cout << &(p->p1) << std::endl;
//    std::cout << &(p->p2) << std::endl;
//  }
//
//  return pairs;
  

//  for (std::vector<Player *>::iterator it = population.begin(); it != population.end(); ++it) {
//    p1 = *it;
//    ++it;
//    if (it != population.end()) {
//      p2 = *it;
//
//      Pair_t *pair = new Pair_t(p1, p2);
////      Pair_t pair(p1, p2);
//      pairs.push_back(&pair);
//    }
//  }
  

  
//
//  int population_index[population.size()];
//  for (int i = 0; i < population.size(); i++) {
//    // 1 to population length
//    population_index[i] = i + 1;
//  }
//
//  long num_pairs = population.size() / 2;
//
//  for (int i = 0; i < num_pairs; i++) {
//
//    int random_index, idx = 0;
//
//    Player *pl1;
//    Player *pl2;
//
//    while (idx == 0) {
//      random_index = rand() % population.size();
//      idx = population_index[random_index];
//    }
//    idx -= 1;
//    pl1 = population[idx];
//    population_index[idx] = 0;
//    idx = 0;
//
//    while (idx == 0) {
//      random_index = rand() % population.size();
//      idx = population_index[random_index];
//    }
//    idx -= 1;
//    pl2 = population[idx];
//    population_index[idx] = 0;
//
////    random_index = rand() % population_index.size();
////    idx = population_index[random_index];
////    population_index.erase(population_index.begin() + random_index);
////    player2 = *population[idx];
//
////    random_index = rand() % pop.size();
////    Player *player2 = pop[random_index];
////    pop.erase(pop.begin() + random_index);
//
//
////    Pair_t *pair = new Pair_t(pl1, pl2);
//    Pair_t pair(pl1, pl2);
//    pairs->push_back(pair);
//
//  }
  

  
  
//  return pairs;
//
//}


void Game::generatePlayers(PlayerConfig *pc) {

  
  for (int i = 0; i < pc->titfortatcoop; ++i) {
    
    Player *pl = new Player;
    TitForTatCoop *st = new TitForTatCoop;
    pl->strategy = st;
    pl->name = "TitForTatCoop";

    population.push_back(pl);
    
  }
  
  for (int i = 0; i < pc->titfortatdefect; ++i) {
    
    Player *pl = new Player;
    TitForTatDefect *st = new TitForTatDefect;
    pl->strategy = st;
    pl->name = "TitForTatDefect";
    
    population.push_back(pl);
    
  }
  

    
}
