#include "rook.h"
#include <iostream>

Rook::Rook(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col): Piece{subject, colour, row, col, 0}, first{1} {}

Rook::~Rook() {}

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

void Rook::notify()
{
	std::pair<int,int> wantedLocation = getSubject()->getWantedLocation();
	if(wantedLocation == this->getLocation())
	{
		std::cout << "It's looking for me! Rook" << std::endl;
	}
}