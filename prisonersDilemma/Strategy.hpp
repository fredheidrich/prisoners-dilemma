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
    
    enum Action
    {
        DEFECT = 0,
        COOPERATE
    };
    
    virtual Action decision() = 0;
    
};



class TitForTat : public Strategy
{
    
    
    virtual Action decision();
};

#endif /* Strategy_hpp */
