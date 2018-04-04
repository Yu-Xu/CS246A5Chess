#include "queen.h"
#include <iostream>

Queen::Queen(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col): Piece{subject, colour, row, col, 0} {}

//, check{false} {}

Queen::~Queen() {}

bool Queen::legalMove(int destinationRow, int destinationCol) {
	int row = getLocation().first;
	int col = getLocation().second;
	if ((row == destinationRow && col != destinationCol) || (row != destinationRow && col == destinationCol)) {
	    return true;
	} else if ((destinationRow - row == col - destinationCol) || (destinationRow - row == destinationCol - col)) {
		return true;
	} else {
	    return false;
	}
}

void Queen::notify()
{
	std::pair<int,int> wantedLocation = getSubject()->getWantedLocation();
	if(wantedLocation == this->getLocation())
	{
		std::cout << "It's looking for me Queen!" << std::endl;
	}
}