#ifndef __CHESSBOARD_H__
#define __CHESSBOARD_H__
#include <string>
#include "subject.h"

class ChessBoard: public Subject {
	std::pair<int,int> moveFrom, moveTo;
public:
	ChessBoard();
	~ChessBoard();
	//big 5?

	//setup mode
	void setPiece(std::pair<int, int> location, std::pair<bool, char> pieceInfo);
	void removePiece(std::pair<int, int> location);

	//standard game board initialization
	void initBoard();

	//move command
	void move(std::pair<int,int> moveFrom, std::pair<int,int> moveTo);
	std::pair<int,int> getMoveFrom() const;
	std::pair<int,int> getMoveTo() const;
};

#endif
