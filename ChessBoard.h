#ifndef __CHESSBOARD_H__
#define __CHESSBOARD_H__
#include <string>
#include "subject.h"

class ChessBoard: public Subject
{
public:
	ChessBoard();
	~ChessBoard();
	
	std::pair<int,int> getWantedLocation() const;
};

#endif
