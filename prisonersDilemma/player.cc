//
//  Player.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include <iostream>

#include "player.h"


void Player::Print() {
  std::cout << strategy->Name() << ": " << score << std::endl;
}


void Player::Move(Player *opponent) {
  
  opponent->interaction_history = strategy->decision(opponent->interaction_history);
  
  (opponent->interaction_history == DEFECT) ? Defect() : Cooperate(opponent);
  
//  if (opponent->interaction_history == DEFECT) {
//    defect();
//  }
//  else if (opponent->interaction_history == COOPERATE) {
//    cooperate(opponent);
//  }
}


void Player::Defect() {
  score += 1;
}

void Player::Cooperate(Player *opponent) {
  opponent->score += 3;
  score -= 1;
}
