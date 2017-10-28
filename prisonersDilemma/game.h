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

struct PlayerConfig
{
  int titfortatcoop;
  int titfortatdefect;
  int pavlov;
  int allcooperate;
  int alldefect;
  int random;
  
};

typedef std::vector<Player*> Players;

class Game
{

public:
  
    void play(Players*);
  
  std::vector<Player*> population;
  
  void endRound(Players*);
  
  void writeStats(Players*, int);
  
  void round(Players*);
  void generatePlayers(std::vector<Player*>& players);


};



#endif /* game_h */
