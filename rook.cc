#include "rook.h"
#include <iostream>

Rook::Rook(ChessBoard* subject, bool colour, int row, int col): Piece{subject, colour, row, col, 0}, first{1} {
	getSubject()->attach(this);
}

Rook::~Rook() {
	getSubject()->detach(this);
}

bool Rook::legalMove(int destinationRow, int destinationCol) {
	int row = getLocation().first;
	int col = getLocation().second;
	if ((row == destinationRow && col != destinationCol) || (row != destinationRow && col == destinationCol)) {
		return true;
	} else {
		return false;
	}
}

bool Rook::getFirst() const {
  return this->first;
}

void Rook::setFirst(bool first) {
  this->first = first;
}

// void Rook::notify()
// {
// 	std::pair<int,int> moveFrom = getSubject()->getMoveFrom();
// 	if(moveFrom == this->getLocation())
// 	{
// 		std::cout << "It's looking for me! Rook" << std::endl;
// 	}
// }
