#include "human.h"

Human::Human(std::string &name, bool &colour):
  Player{name, colour} {}

Human::~Human() {}

std::pair<std::pair<int, int>, std::pair<int, int>> Human::getMove() {
  
}
