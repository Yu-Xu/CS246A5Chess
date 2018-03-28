#include "player.h"

Player::Player(bool colour): player{""}, colour{colour}, queen{}, king{}
 , knights{}, bishops{}, rocks{}, pawns{} {}

Player::~Player() {}

void Player::setPlayer(std::string p) {
  this->player = p;
}

void Player::setLevel(int l) {
  return;
}

std::vector<std::pair<int, int>> &Player::getRocks() {
  return rocks;
}
std::vector<std::pair<int, int>> &Player::getBishops() {
  return bishops;
}
std::vector<std::pair<int, int>>&Player::getKnights() {
  return knights;
}
std::vector<std::pair<int, int>> &Player::getPawns() {
  return pawns;
}
std::vector<std::pair<int, int>> &Player::getKing() {
  return king;
}

std::vector<std::pair<int, int>> &Player::getQueen() {
  return queen;
}

bool Player::getColour() {
  return colour;
}
