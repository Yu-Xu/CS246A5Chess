#include "emptycell.h"
#include <iostream>

EmptyCell::EmptyCell(ChessBoard* subject, bool colour, int row, int col): 
Piece{subject, colour, row, col, 0} {
	getSubject()->attach(this);
}

EmptyCell::~EmptyCell() {
	getSubject()->detach(this);
}

bool EmptyCell::legalMove(int destinationRow, int destinationCol)
{
	return true;
}

// void EmptyCell::notify()
// {
// 	std::pair<int,int> moveFrom = getSubject()->getMoveFrom();
// 	if(moveFrom == this->getLocation())
// 	{
// 		std::cout << "It's looking for me EmptyCell!" << std::endl;
// 	}
// }
