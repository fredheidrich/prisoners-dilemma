//
//  Game.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include "Game.hpp"


void Game::round()
{
    

    
    
}


std::vector<Game::Pair_t> Game::generatePairs()
{
    
    std::vector<Player*> pop = population;
    
    std::vector<Pair_t> pairs;
    
    long num_pairs = pop.size() / 2;
    
    for (int i = 0; i < num_pairs; i++)
    {
        int random_index = rand() % pop.size();
        Player *Player1 = pop[random_index];
        pop.erase(pop.begin() + random_index);
        
        random_index = rand() % pop.size();
        Player *Player2 = pop[random_index];
        pop.erase(pop.begin() + random_index);
        
    
        Pair_t pair = { Player1, Player2 };
        
        pairs.push_back(pair);
        
    }
    
    return pairs;
    
}


void Game::generatePlayers(PlayerConfig *pc)
{
    
    int numStrategies = 2;
    for (int i = 0; i < numStrategies; i++)
    {
        for (int j = 0; j < pc->titfortatcoop; j++)
        {

            Strategy *strat = new TitForTatCoop();
            Player *p = new Player(strat);
            population.push_back(p);
            
        }
        
        for (int j = 0; j < pc->titfortatdefect; j++)
        {
//            Strategy *strat = new TitForTatCoop();
            Player *p = new Player();
            population.push_back(p);
            
        }
        
    }
    
}
