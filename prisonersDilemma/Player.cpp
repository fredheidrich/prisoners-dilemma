//
//  Player.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include "Player.hpp"


void Player::defect()
{
    
    score += 1;
}

void Player::cooperate(Player *opponent)
{
    
    opponent->score += 3;
    
    score -= 1;
}
