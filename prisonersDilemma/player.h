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
  
  void defect();
  void cooperate(Player*);
    
public:
  
//  Player() : score(0) {};
  
  void move(Player*);

  Interaction memory;
  Interaction interaction_history;
  
//  Player(Strategy *strategy) : strategy(strategy) {};
  
  int score = 0;
  
  Strategy *strategy;

};


#endif /* player_h */
