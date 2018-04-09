 #include <iostream>
 #include "ChessBoard.h"
 #include "piece.h"
 #include "pawn.h"
 #include "rook.h"
 #include "bishop.h"
 #include "knight.h"
 #include "king.h"
 #include "queen.h"
 #include "emptycell.h"
 
 int main()
 {
 	std::shared_ptr<ChessBoard> testBoardPtr = std::make_shared<ChessBoard>();
 
 	// Pawn p1{testBoardPtr, 1, 3, 5};
 	// Rook r1{testBoardPtr, 1, 2, 4};
 	// Bishop b1{testBoardPtr, 1, 3, 2};
 	// Knight n1{testBoardPtr, 1, 3, 9};
 	// King k1{testBoardPtr, 1, 2, 9};
 	// Queen q1{testBoardPtr, 1, 1, 7};
 	// EmptyCell e1{testBoardPtr, 1, 3, 4};

 	Bishop b1{testBoardPtr, 1, 2, 4};
 	Pawn p1{testBoardPtr, 1, 1, 5};
 	Pawn p2{testBoardPtr, 1, 4, 2};
 
 	testBoardPtr->move(std::pair<int,int>(2,4), std::pair<int,int>(0,5));
	

 	return 0;
 }