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
  
  
  
  void PrintStats();
  
  
  
public:
  
  
    
  void Round(int8_t);
    void play(Players*, int, int probability = 0);
  
  std::vector<Player*> population;
  
  void Play(int, int8_t);

  
  void endRound(Players*);
  
  
  void writeStats(std::string, Players*, int);
  
  void round(int, Players*);
  void generatePlayers(PlayerConfig pc, std::vector<Player*>& players);
  void generatePlayers(PlayerConfig pc);


};



#endif /* game_h */
