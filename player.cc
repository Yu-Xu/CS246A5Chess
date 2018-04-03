#include "player.h"

Player::Player(bool colour): name{""}, colour{colour}, queen{}, king{}
 , knights{}, bishops{}, rooks{}, pawns{} {}

Player::Player(std::string name, bool colour): name{name}, colour{colour}, queen{}, king{}
 , knights{}, bishops{}, rooks{}, pawns{} {}

Player::~Player() {}

void Player::setPlayerName(std::string name) {
  this->name = name;
}

void Player::setLevel(int l) {
  return;
}

std::vector<std::pair<int, int>> &Player::getRooks() {
  return rooks;
}
std::vector<std::pair<int, int>> &Player::getBishops() {
  return bishops;
}
std::vector<std::pair<int, int>> &Player::getKnights() {
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

std::string Player::getPlayerName(){
	return this->name;
}

// std::pair< std::pair<int, int>, std::pair<int, int> > Player::makeAMove()
// {
// 	std::cout << "WE are in player.cc's makeAMove" << std::endl;
// 	return std::pair< std::pair<int, int>, std::pair<int, int> >();
// }
