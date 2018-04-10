#include <iostream>
#include <string>
#include "subject.h"
#include "ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard() {}

ChessBoard::~ChessBoard() {}

//setup mode
void ChessBoard::setPiece(pair<int, int> location, pair<bool, char> pieceInfo) {

}
void ChessBoard::removePiece(pair<int, int> location) {

}

//standard game board initialization
void ChessBoard::initBoard() {
	for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if ((i >= 0 && i <=1) || (i >= 6 && i <=7)) {
        if (j == 0 || j == 7) { // set  rooks
          if (i == 0) board[i][j].setPiece("r", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("R", 1);
        } else if (j == 1 || j == 6) { // set  knights
          if (i == 0) board[i][j].setPiece("n", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("N", 1);
        }  else if (j == 2 || j == 5) { // set  bishops
          if (i == 0) board[i][j].setPiece("b", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("B", 1);
        } else if (j == 3) { // set queens
          if (i == 0) board[i][j].setPiece("q", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("Q", 1);
        } else if (j == 4) {  // set kings
          if (i == 0) board[i][j].setPiece("k", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("K", 1);
        }
      }
    }
	}
}

void ChessBoard::move(pair<int,int> moveFrom, pair<int,int> moveTo) {
	this->moveFrom = moveFrom;
	this->moveTo = moveTo;
	//cout << moveFrom.first << ", " << moveFrom.second << " and " << moveTo.first << ", " << moveTo.second << endl;
	//notifyObservers();
	if(notifyObservers())	{
		cout << "Successful move!" << endl;
	}	else {
		cout << "Unsuccessful move, you should try again!" << endl;
	}
}

pair<int,int> ChessBoard::getMoveFrom() const {
	return this->moveFrom;
}

pair<int,int> ChessBoard::getMoveTo() const {
	return this->moveTo;
}
