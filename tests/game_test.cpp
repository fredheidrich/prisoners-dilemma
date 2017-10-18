//
//  game_test.cpp
//  tests
//
//  Created by Frederick Heidrich on 13/10/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include <stdio.h>
//#include <gtest/gtest.h>

//class GameTest : public ::testing::Test {
//protected:
//    GameTest() {}
//};
//
//TEST_F(GameTest, test) {
//
//}

#include "inc/catch.hpp"

#include "game.h"

TEST_CASE( "General", "[game]" ) {
    
    Game g;
    PlayerConfig cfg = {
        4,
    };
    std::vector<Player*> players;
    g.generatePlayers(cfg, players);
    
    REQUIRE(players.size() != 0);
    
    // make pairs
    std::random_shuffle(players.begin(), players.end());
    
    REQUIRE(players.size() != 0);
    
    SECTION("Starting a round") {
        
//        g.round(75, &players);
        
        REQUIRE(players[0]->score == 0);
        
        g.play(&players, 1, 75);
        
        REQUIRE(players[0]->score != 0);
        
        players[0]->score = -1;
        g.endRound(&players);
        
        REQUIRE(players.size() == 3);
        
        players[0]->score = 101;
        g.endRound(&players);
        
        REQUIRE(players.size() == 4);
        
        std::string filename = "test.tsv";
        g.writeStats(filename, &players, 1);
        
    }
    
}
