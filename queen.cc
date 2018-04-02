#include "queen.h"

Queen::Queen(std::string s, bool colour, int row, int col): Piece{s, colour, row, col} {}

//, check{false} {}

Queen::~Queen() {}

bool Queen::legalMove(int row, int col) {
  // std::cout << "Pawn r " << r << " c " << c << std::endl;
  // std::cout << "Pawn row " << row << " col " << col << std::endl;
  if ((r == row && c != col) || (r != row && c == col)) {
    return true;
  } else {
    if ((row - r == c - col) || (row - r == col - c)) {
      return true;
    } else {
      return false;
    }
  }
}
