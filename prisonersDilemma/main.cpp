//
//  main.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
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
    
    
    
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
