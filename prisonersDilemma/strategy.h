//
//  strategy.h
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#ifndef strategy_h
#define strategy_h

#include <stdio.h>

//#include "player.h"


enum Interaction
{
  NONE = 0,
  DEFECT,
  COOPERATE
};


// Abstract class
class Strategy {
  
public:
  virtual Interaction decision(Interaction) = 0;
    
};


class TitForTatCoop : public Strategy {
    
public:
  virtual Interaction decision(Interaction i) { return (i == DEFECT) ? DEFECT : COOPERATE; };
  
};

#endif /* strategy_h */
