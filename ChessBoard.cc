#include <iostream>
#include <string>
#include "subject.h"
#include "ChessBoard.h"

ChessBoard::ChessBoard() {}

ChessBoard::~ChessBoard() {}

std::pair<int,int> ChessBoard::getWantedLocation() const
{
	return std::pair<int,int>(3,4);
}
