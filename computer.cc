#include "computer.h"

Computer::Computer(bool colour): Player{player, colour}
, level{-1} {}


Computer::~Computer() {}

void Computer::setLevel(int l) {
  this->level = l;
}
