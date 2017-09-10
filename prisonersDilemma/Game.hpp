//
//  Game.hpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <vector>

#include "Player.hpp"

class Game
{
    
    
    void round();
    
    std::vector<Player*> population;
    
public:
    
    Game() {};
    
    ~Game() {};
    
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


};



#endif /* Game_hpp */
