#include "pawn.h"
#include <iostream>

Pawn::Pawn(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col): Piece{subject, colour, row, col, 0}, first{1}, passant{0} {
	getSubject()->attach(this);
}

Pawn::~Pawn() {
  getSubject()->detach(this);
}

bool Pawn::legalMove(int destinationRow, int destinationCol) {
  int vdist;
  int row = getLocation().first;
  int col = getLocation().second;
  if (row > destinationRow) {
    vdist = row - destinationRow;
  } else {
    vdist = destinationRow - row;
  }

  int hdist = destinationCol - col;

  if (first == true) { // first step
    if (((vdist == 1) || (vdist == 2)) && destinationCol == col) { //first step move 1 or 2 forward
      if (vdist == 2) {
        this->passant = 1;
      }
      return true;
    } else if ((vdist == 1) && ((hdist == 1) || (hdist == -1))) { //otherwise captures on forward square
      return true;
    }
  } else {
    if ((vdist == 1) && (destinationCol == col || (hdist == 1) || (hdist == -1))) {
      return true;
    } else {
      return false;
    }
  }

  return false;
}

bool Pawn::getPassant() const{
  return this->passant;
}

bool Pawn::getFirst() const{
  return this->first;
}

void Pawn::setPassant(bool passant) {
  this->passant = passant;
}

void Pawn::setFirst(bool first) {
  this->first = first;
}

void Pawn::notify() {
	std::pair<int,int> moveFrom = getSubject()->getMoveFrom();

	if(moveFrom == this->getLocation())
	{
		std::cout << "It's looking for me Pawn!" << std::endl;
    std::pair<int,int> moveTo = getSubject()->getMoveTo();
    if(legalMove(moveTo.first, moveTo.second))
    {
      std::cout << "It's a legit move mate!" << std::endl;
    }
    else
    {
      std::cout << "I wont allow this move!" << std::endl;

    }
	}
}
