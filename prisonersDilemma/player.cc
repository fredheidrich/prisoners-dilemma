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


void Player::move(Player& opponent) {
  
  this->against = opponent.ID;
  
  // make decision based on strategy
  switch (strat) {
    case ttc:
      this->myInteractionThisRound = (this->opponentsInteractionLastRound == DEFECT) ? DEFECT : COOPERATE;
      break;
    case ttd:
      this->myInteractionThisRound = (this->opponentsInteractionLastRound == COOPERATE) ? COOPERATE : DEFECT;
      break;
    case def:
      this->myInteractionThisRound = DEFECT;
      break;
    case coop:
      this->myInteractionThisRound = COOPERATE;
      break;
    case rnd:
      int rnd = distribution(engine);
      this->myInteractionThisRound = (rnd <= 50) ? COOPERATE : DEFECT;
      break;
  }
  
  // take action
  if (this->myInteractionThisRound == DEFECT) {
    this->defect();
  } else {
    this->cooperateWith(opponent);
  }
  
}


void Player::defect() {
  this->score += 1;
}

void Player::cooperateWith(Player& opponent) {
  opponent.score += 4;
  this->score -= 1;
}
