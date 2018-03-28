#include "Rock.h"

Rock::Rock(std::string s, bool colour, int row, int col): Piece{s, colour, row, col}, first{1} {}

//, check{false} {}

Rock::~Rock() {}

bool Rock::legalMove(bool player, int row, int col) {
  if (player == colour) {
    // std::cout << "Pawn r " << r << " c " << c << std::endl;
    // std::cout << "Pawn row " << row << " col " << col << std::endl;
    if ((r == row && c != col) || (r != row && c == col)) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool Rock::getFirst() {
  return this->first;
}

void Rock::setFirst(bool first) {
  this->first = first;
}
