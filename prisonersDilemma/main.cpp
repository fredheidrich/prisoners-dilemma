//
//  main.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich and Dan Agnew on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include <iostream>
#include <map>

#include "game.h"

// Abstract class
class Base {
public:
  virtual void func() = 0;
};

class Derived: public Base {
public:
  virtual void func() { std::cout << "hello" << std::endl; }
};

class C {
public:
  Base *a;
};



int main(int argc, const char * argv[]) {
  
//  C *c = new C;
//
//  Derived d;
//  c->a = &d;
//  c->a->func(); // returns hello
  
  
  
  PlayerConfig cfg = {
      .titfortatcoop = 4,
  };
  

  Game game;
  
  std::vector<Player*> players;
  game.generatePlayers(cfg, players);
  
  int rounds = 100;
  int8_t probability = 75;
  
  game.play(&players, rounds, probability);
  
  return 0;
}
