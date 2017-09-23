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


enum Interaction
{
  NONE = 0,
  DEFECT,
  COOPERATE
};


// Abstract class
class Strategy {
  const char *name = "Strategy";
public:
  virtual const char *Name() = 0;
  virtual Interaction decision(Interaction) = 0;
    
};


class TitForTatDefect : public Strategy {
  const char *name = "Tit for tat defect";
public:
  virtual const char *Name() { return name; };
  virtual Interaction decision(Interaction i) { return (i == COOPERATE) ? COOPERATE : DEFECT; };
  
};


class TitForTatCoop : public Strategy {
  const char *name = "Tit for tat coop";
public:
  virtual const char *Name() { return name; };
  virtual Interaction decision(Interaction i) { return (i == DEFECT) ? DEFECT : COOPERATE; };
  
};

#endif /* strategy_h */
