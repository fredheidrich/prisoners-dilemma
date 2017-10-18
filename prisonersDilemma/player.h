//
//  Player.hpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#ifndef player_h
#define player_h

#include <stdio.h>
#include <iostream>
#include "strategy.h"




enum Strat {
  ttc = 0,
  ttd,
};

static int num_id;

class Player {
  void Defect();
  void Cooperate(Player*);
public:
  
  
    Player(): strat(ttc), ID(num_id++), memory(NONE), interaction_history(NONE) {};
  Player(Strat s):
    strat(s), score(0), ID(num_id++), memory(NONE), interaction_history(NONE) {};
  ~Player() {
    std::cout << "Player " << ID << " destroyed\n";
  };
  
  const int ID;
  
    void makeDecision(Strat, Interaction, Interaction&);
    void cooperate(Player&);
    
  void Print();
  void Move(Player*);
  void move(Player&);

  Interaction memory;
  Interaction interaction_history;
  
  int score;
  Strategy *strategy;
  Strat strat;

};


#endif /* player_h */
