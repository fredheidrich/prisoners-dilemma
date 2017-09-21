//
//  main.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich and Dan Agnew on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include <iostream>
#include <map>

#include "Game.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    

    
    Game::PlayerConfig pc = {
        .titfortatcoop = 3,
        .titfortatdefect = 3,
    };


    
//    std::map<Player::Strategy, int> m_pc;
    
    
    
    Game game;
    
    game.generatePlayers(&pc);
    
    int rounds = 1;
    
    
    for (int i = 0; i < rounds; i++)
    {
        std::vector<Game::Pair_t> pairs = game.generatePairs();
        
        bool interaction = true;
        while (interaction)
        {
            for (int j = 0; j < pairs.size(); j++)
            {
                Game::Pair_t pair = pairs.back();
                
                
                Player *prisoner1 = std::get<0>(pair);
                Player *prisoner2 = std::get<1>(pair);
                
                prisoner1->move(prisoner2);
                prisoner2->move(prisoner1);

//                prisoner1->memory = prisoner1->interaction_history;
//                prisoner2->memory = prisoner2->interaction_history;
                
                
            }
            
            
            interaction = false;
        }
        
    }
    
    
    
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
