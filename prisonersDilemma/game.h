//
//  game.h
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#ifndef game_h
#define game_h

#include <stdio.h>
#include <vector>

#include "player.h"

class Game
{
  
  void Round(int8_t);
  
  void PrintStats();
  
  std::vector<Player*> population;
  
public:
  
  void Play(int, int8_t);
  
  typedef std::tuple<Player*, Player*> Pair_t;
  
  
  
  typedef struct Pair {
    Player *p1;
    Player *p2;
  } Pair;
  
  
  typedef struct PlayerConfig
  {
    int titfortatcoop;
    int titfortatdefect;
    int pavlov;
    int allcooperate;
    int alldefect;
    int random;
    
  }PlayerConfig;
  
  void generatePlayers(PlayerConfig *pc);
  Pair *generatePairs();

};



#endif /* game_h */
