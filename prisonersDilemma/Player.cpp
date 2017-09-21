//
//  Player.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include "Player.hpp"


void Player::move(Player *opponent)
{
    opponent->interaction_history = strategy->decision(opponent->interaction_history);
    
    if (opponent->interaction_history == Strategy::DEFECT)
    {
        defect();
    }
    else if (opponent->interaction_history == Strategy::COOPERATE)
    {
        cooperate(opponent);
    }
}


void Player::defect()
{
    
    score += 1;
}

void Player::cooperate(Player *opponent)
{
    
    opponent->score += 3;
    
    score -= 1;
}
