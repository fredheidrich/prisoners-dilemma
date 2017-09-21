//
//  Strategy.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include "Strategy.hpp"


TitForTatCoop::Action decision(Strategy::Action a)
{
    
    // logic for tit for tat
    
    if (a == Strategy::DEFECT)
    {
        return Strategy::DEFECT;
    }
    else if (a == Strategy::COOPERATE)
    {
        return Strategy::COOPERATE;
    }
    else
    {
        return Strategy::COOPERATE;
    }
    
}
