#include "bishop.h"
#include <iostream>

Bishop::Bishop(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col): Piece{subject, colour, row, col, 0} {
  getSubject()->attach(this);
}


Bishop::~Bishop() {
  getSubject()->detach(this);
}

bool Bishop::legalMove(int destinationRow, int destinationCol) {
  int row = getLocation().first;
  int col = getLocation().second;
  if (row != destinationRow && col != destinationCol) {
    if ((destinationRow - row == col - destinationCol) || (destinationRow - row == destinationCol - col)) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void Bishop::notify()
{
    std::pair<int,int> moveFrom = getSubject()->getMoveFrom();
    if(moveFrom == this->getLocation())
    {
      std::cout << "It's looking for me! Bishop" << std::endl;
    }
}