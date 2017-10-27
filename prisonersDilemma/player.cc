//
//  Player.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include <iostream>

#include "player.h"
#include <random>

std::random_device rd;
std::uniform_int_distribution<int> distribution(1, 100);
std::mt19937 engine(rd()); // Mersenne twister MT19937

void Player::Print() {
  std::cout << "ID: "<< this->ID << ": " << score << "\n";
}

void Player::makeDecision(Strat strat, Interaction opponent_hist, Interaction& my_interaction) {
  
  switch (strat) {
    case ttc:
      my_interaction = (opponent_hist == DEFECT) ? DEFECT : COOPERATE;
      break;
    case ttd:
      my_interaction = (opponent_hist == COOPERATE) ? COOPERATE : DEFECT;
      break;
    case def:
      my_interaction = DEFECT;
      break;
    case coop:
      my_interaction = COOPERATE;
      break;
    case rnd:
      int rnd = distribution(engine);
      my_interaction = (rnd <= 50) ? COOPERATE : DEFECT;
      break;
  }

}


void Player::move(Player& opponent) {
  
  makeDecision(this->strat, opponent.interaction_history, this->memory);
  
  (this->memory == DEFECT) ? defect() : cooperate(opponent);
  
}



void Player::Defect() {
  score += 1;
}

void Player::defect() {
  this->score += 1;
}

void Player::cooperate(Player& opponent) {
  opponent.score += 3;
  this->score -= 1;
}

void Player::Cooperate(Player *opponent) {
  opponent->score += 3;
  score -= 1;
}
