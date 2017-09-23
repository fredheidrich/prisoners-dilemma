//
//  Player.cpp
//  prisonersDilemma
//
//  Created by Frederick Heidrich on 8/9/17.
//  Copyright © 2017 bitslice. All rights reserved.
//

#include "player.h"


void Player::move(Player *opponent) {
  
  opponent->interaction_history = strategy->decision(opponent->interaction_history);
  
  (opponent->interaction_history == DEFECT) ? defect() : cooperate(opponent);
  
//  if (opponent->interaction_history == DEFECT) {
//    defect();
//  }
//  else if (opponent->interaction_history == COOPERATE) {
//    cooperate(opponent);
//  }
}


void Player::defect() {
  
  score += 1;

}

void Player::cooperate(Player *opponent) {
  
  opponent->score += 3;
  score -= 1;
  
}
