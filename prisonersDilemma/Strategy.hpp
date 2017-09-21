//
//  Strategy.hpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#ifndef Strategy_hpp
#define Strategy_hpp

#include <stdio.h>

class Strategy
{
    
    
public:
    
    Strategy() {};
    ~Strategy() {};
    
    enum Action
    {
        NONE = 0,
        DEFECT,
        COOPERATE
    };
    
//    virtual Action decision(Action a) = 0;
    
};



class TitForTatCoop : public Strategy
{
    
public:
    TitForTatCoop() {};
    ~TitForTatCoop() {};

    
    Action decision(Action a);
};

#endif /* Strategy_hpp */
