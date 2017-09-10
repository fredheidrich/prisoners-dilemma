//
//  Game.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include "Game.hpp"


void Game::round()
{
    

    
    
}

void Game::generatePlayers(PlayerConfig *pc)
{
    
    int numStrategies = 2;
    for (int i = 0; i < numStrategies; i++)
    {
        for (int j = 0; j < pc->titfortatcoop; j++)
        {

            Player *p = new Player(Player::TIT_FOR_TAT_COOP);
            population.push_back(p);
            
        }
        
        for (int j = 0; j < pc->titfortatdefect; j++)
        {
            
            Player *p = new Player(Player::TIT_FOR_TAT_DEFECT);
            population.push_back(p);
            
        }
        
    }
    
}
