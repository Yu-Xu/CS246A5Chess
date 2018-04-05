#ifndef __PIECE_H__
#define __PIECE_H__
#include <memory>
#include <utility>
#include "observer.h"
#include "ChessBoard.h"

class Piece: public Observer
{
	std::shared_ptr<ChessBoard> subject;
	bool colour; //black or white
	std::pair<int, int> location;
	bool empty;
	
public:
	Piece();
	Piece(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col, bool empty);
	~Piece();
	
	bool isEmpty() const;
	bool getColour() const;
	std::pair<int,int> getLocation() const;
	ChessBoard * getSubject() const;

	virtual bool legalMove(int destinationRow, int destinationCol) = 0;
};

#endif
