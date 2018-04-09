#include <iostream>
#include <string>
#include "subject.h"
#include "ChessBoard.h"

ChessBoard::ChessBoard() {}

ChessBoard::~ChessBoard() {}

void ChessBoard::move(std::pair<int,int> moveFrom, std::pair<int,int> moveTo)
{
	this->moveFrom = moveFrom;
	this->moveTo = moveTo;
	//std::cout << moveFrom.first << ", " << moveFrom.second << " and " << moveTo.first << ", " << moveTo.second << std::endl;
	//notifyObservers();
	if(notifyObservers())
	{
		std::cout << "Successful move!" << std::endl;
	}
	else
	{
		std::cout << "Unsuccessful move, you should try again!" << std::endl;
	}
}

std::pair<int,int> ChessBoard::getMoveFrom() const
{
	return this->moveFrom;
}

std::pair<int,int> ChessBoard::getMoveTo() const
{
	return this->moveTo;
}
