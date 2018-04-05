#include "emptycell.h"
#include <iostream>

EmptyCell::EmptyCell(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col): 
Piece{subject, colour, row, col, 0} {}

EmptyCell::~EmptyCell() {}

bool EmptyCell::legalMove(int destinationRow, int destinationCol)
{
	return true;
}

void EmptyCell::notify()
{
	std::pair<int,int> wantedLocation = getSubject()->getWantedLocation();
	if(wantedLocation == this->getLocation())
	{
		std::cout << "It's looking for me EmptyCell!" << std::endl;
	}
}
