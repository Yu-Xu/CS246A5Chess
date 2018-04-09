#ifndef __CHESSBOARD_H__
#define __CHESSBOARD_H__
#include <string>
#include "subject.h"

class ChessBoard: public Subject
{
	std::pair<int,int> moveFrom, moveTo;
public:
	ChessBoard();
	~ChessBoard();
	
	void move(std::pair<int,int> moveFrom, std::pair<int,int> moveTo);
	std::pair<int,int> getMoveFrom() const;
	std::pair<int,int> getMoveTo() const;
};

#endif
