#include "player.h"

using namespace std;

Player::Player() {}

Player::Player(string &name, bool &colour):
  name{name}, colour{colour} {}

Player::~Player() {}

string Player::getName() {
  return name;
}

bool Player::getColour() {
  return colour;
}
