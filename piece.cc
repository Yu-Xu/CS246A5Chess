#include "piece.h"
#include <iostream>
#include <cmath>
#include <algorithm>

Piece::Piece(): subject{std::make_shared<ChessBoard>()}, colour{0}, location{std::pair<int,int>{-1, -1}}, empty{1} {
	std::cout << "ARE WE HERE" << std::endl;
}

Piece::Piece(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col, bool empty): subject{subject}, colour{colour}, location{std::pair<int,int>{row,col}}, empty{empty} {}

Piece::~Piece() {}

bool Piece::isEmpty() const
{
	return this->empty;
}

bool Piece::getColour() const
{
	return this->colour;
}

std::pair<int,int> Piece::getLocation() const
{
	return this->location;
}
ChessBoard * Piece::getSubject() const
{
	return this->subject.get();
}

//Since this is common for all pieces, I decided to put it in this class
//It will call the corresponding legalMove() which is overridden in the subclasses themselves
void Piece::notify() {
	std::pair<int,int> moveFrom = getSubject()->getMoveFrom();
	std::pair<int,int> moveTo = getSubject()->getMoveTo();
	std::pair<int,int> pieceLocation = this->getLocation();

	if(moveFrom == pieceLocation) //Case where this is the piece we want to move
	{
    	if(this->isEmpty())
    	{
    		//return false; //Cant move an empty piece
    	}
	    if(legalMove(moveTo.first, moveTo.second))
	    {
	      std::cout << "It's a legit move mate!" << std::endl;
	      //return true;
	    }
	    else
	    {
	      std::cout << "I wont allow this move!" << std::endl;
	      //return false;
	    }
	}
	else //Cases where the current piece is in the way of the move
	{
		//Horizontal move
		if(moveFrom.first == moveTo.first)
		{
			if(pieceLocation.first == moveFrom.first && 
				pieceLocation.second > std::min(moveFrom.second, moveTo.second) && 
				pieceLocation.second < std::max(moveFrom.second, moveTo.second))
			{
				std::cout << "In the way!" << std::endl;
			}
		}
		//Vertical move
		else if(moveFrom.second == moveTo.second)
		{
			if(pieceLocation.second == moveFrom.second && 
				pieceLocation.first > std::min(moveFrom.first, moveTo.first) && 
				pieceLocation.first < std::max(moveFrom.first, moveTo.first))
			{
				std::cout << "In the way!!" << std::endl;
			}
		}
		//Diagonal move
		else if((moveFrom.first + moveFrom.second) == (moveTo.first + moveTo.second) || 
			(std::abs(moveFrom.first - moveFrom.second) == std::abs(moveTo.first - moveTo.second)))
		{
			if( ( ( (pieceLocation.first - pieceLocation.second) == (moveFrom.first - moveFrom.second) || 
				(pieceLocation.first + pieceLocation.second) == (moveFrom.first + moveFrom.second) ) ) &&
				(pieceLocation.first > std::min(moveFrom.first, moveTo.first) ) &&
				(pieceLocation.first < std::max(moveFrom.first, moveTo.first) ) )
			{
				std::cout << "In the way!!!" << std::endl;
			}
		}
	}

	

	
}
