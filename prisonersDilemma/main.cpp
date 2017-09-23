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
//
//  c->a->func(); // returns hello
  
  
  
  Game::PlayerConfig pc = {
      .titfortatcoop = 4,
      .titfortatdefect = 4,
  };
  
  // TODO(fred): make sure player num is devidable by 2
  // we need this for pairing up players two and two

  Game game;
  game.generatePlayers(&pc);
  
  int rounds = 1;
  int8_t probability = 75;
  
  game.Play(rounds, probability);
  
  return 0;
}
