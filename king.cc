#include "king.h"
#include <iostream>

King::King(ChessBoard* subject, bool colour, int row, int col):
  Piece{subject, colour, row, col, 0}, first{1} {
    getSubject()->attach(this);
  }

King::~King() {
  getSubject()->detach(this);
}

bool King::legalMove(int destinationRow, int destinationCol) {
  int row = getLocation().first;
  int col = getLocation().second;
  int hdist = destinationCol - col;
  int vdist = destinationRow - row;
  if ((hdist == 1 || hdist == -1 || hdist == 0) &&
    (vdist == 1 || vdist == -1 || vdist == 0)) {
      return true;
  } else if ((vdist == 0) && (hdist == 2 || hdist == -2) && first) {
    return true;
  } else {
    return false;
  }
}

bool King::getFirst() const{
  return this->first;
}

void King::setFirst(bool first) {
  this->first = first;
}

// void King::notify()
// {
//   std::pair<int,int> moveFrom = getSubject()->getMoveFrom();
//   if(moveFrom == this->getLocation())
//   {
//     std::cout << "It's looking for me King!" << std::endl;
//   }
// }
