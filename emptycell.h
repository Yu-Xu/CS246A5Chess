#ifndef __EMPTYCELL_H__
#define __EMPTYCELL_H__
#include "piece.h"
#include <iostream>

class EmptyCell: public Piece
{
public:
	EmptyCell(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col);
	~EmptyCell();
	
	//void notify() override;
	bool legalMove(int destinationRow, int destinationCol) override;

};
#endif
