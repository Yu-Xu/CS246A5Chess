#include "knight.h"

Knight::Knight(std::string s, bool colour, int row, int col): Piece{s, colour, row, col} {}

//, check{false} {}

Knight::~Knight() {}

bool Knight::legalMove(int row, int col) {
  if (((row == r - 2 || row == r + 2) && (col == c - 1 || col == c + 1)) ||
    ((row == r - 1 || row == r + 1) && (col == c - 2 || col == c + 2))) {
    return true;
  } else {
    return false;
  }
}
