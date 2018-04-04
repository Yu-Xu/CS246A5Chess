#include "knight.h"
#include <iostream>

Knight::Knight(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col): Piece{subject, colour, row, col, 0} {}

Knight::~Knight() {}

bool Knight::legalMove(int destinationRow, int destinationCol) {
	int row = getLocation().first;
	int col = getLocation().second;
	if (((destinationRow == row - 2 || destinationRow == row + 2) && (destinationCol == col - 1 || destinationCol == col + 1)) ||
	((destinationRow == row - 1 || destinationRow == row + 1) && (destinationCol == col - 2 || destinationCol == col + 2))) {
		return true;
	} else {
		return false;
	}
}
void Knight::notify()
{
	std::pair<int,int> wantedLocation = getSubject()->getWantedLocation();
	if(wantedLocation == this->getLocation())
	{
		std::cout << "It's looking for me Knight!" << std::endl;
	}
}