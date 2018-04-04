#include <iostream>
#include "ChessBoard.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "king.h"
#include "queen.h"

int main()
{
	ChessBoard testBoard;
	std::make_unique<ChessBoard>(testBoard);

	Pawn p1{std::make_unique<ChessBoard>(testBoard), 1, 3, 5};
	Rook r1{std::make_unique<ChessBoard>(testBoard), 1, 2, 4};
	Bishop b1{std::make_unique<ChessBoard>(testBoard), 1, 3, 8};
	Knight n1{std::make_unique<ChessBoard>(testBoard), 1, 3, 9};
	King k1{std::make_unique<ChessBoard>(testBoard), 1, 2, 9};
	Queen q1{std::make_unique<ChessBoard>(testBoard), 1, 3, 4};
	Pawn * ptrP = &p1;
	Rook * ptrR = &r1;
	Bishop * ptrB = &b1;
	Knight * ptrN = &n1;
	King * ptrK = &k1;
	Queen * ptrQ = &q1;
	testBoard.attach(ptrP);
	testBoard.attach(ptrR);
	testBoard.attach(ptrB);
	testBoard.attach(ptrN);
	testBoard.attach(ptrK);
	testBoard.attach(ptrQ);
	testBoard.notifyObservers();
	return 0;
}