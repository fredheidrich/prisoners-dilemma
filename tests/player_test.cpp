//
//  player_test.cpp
//  tests
//
//  Created by Frederick Heidrich on 13/10/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include <stdio.h>

#include "inc/catch.hpp"
#include "player.h"

TEST_CASE("Player tests", "[player]") {
    
    Player p1(ttc);
    REQUIRE(p1.strat == ttc);
    
    Player p2;
    REQUIRE(p2.strat == ttc);
    
    p1.move(p2);
    
    REQUIRE(p1.score != 0);
    REQUIRE(p2.score != 0);
    REQUIRE(p1.myInteractionThisRound == COOPERATE);
    REQUIRE(p2.memory == NONE);
    
    p2.move(p1);
    REQUIRE(p2.memory == COOPERATE);
}
