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

#include "strategy.h"


class Player {
  
  
  void Defect();
  void Cooperate(Player*);
    
public:
  
  void Print();
//  Player() : score(0) {};
  
  void Move(Player*);

  Interaction memory;
  Interaction interaction_history;
  
//  Player(Strategy *strategy) : strategy(strategy) {};
  
  int score = 0;
  const char *name = "";
  Strategy *strategy;

};


#endif /* player_h */
