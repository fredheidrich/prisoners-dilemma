//
//  Player.hpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

#include "Strategy.hpp"

class Player
{
    
    
    void defect();
    void cooperate(Player *opponent);
    
public:
    
    

    
//    enum Strategy
//    {
//        TIT_FOR_TAT_COOP = 0,
//        TIT_FOR_TAT_DEFECT
//    };
    
    Strategy::Action lastAction;
    
    
    Player(int strategy) : strategy(strategy) {};
    
    ~Player();
    
    
    int score;
    
    
    int strategy;
};


#endif /* Player_hpp */
