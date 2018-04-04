#ifndef CHESSB_H
#define CHESSB_H
#include <iostream>
#include <vector>
#include <utility>
#include "cell.h"
#include <string>

class Observer;

class ChessBoard {
  //a board consists of the vector vector Cells 8x8 cells
  std::vector<std::vector<Piece>> board;
  //text display

  //graphics display

  //observer intented for graphics??????



  //square size 8, don't need?
  int size;

 public:
  ChessBoard();
  ~ChessBoard();

  void clearBoard();
  std::vector<std::vector<Cell>> &getBoard();

  void init(); // Sets up an n x n grid.  Clears old grid, if necessary.

  //determine if move is blocked?


  void addPiece(int r, int c, std::string type, bool colour);
  void removePiece(int r, int c);
  void setUpOb();
  void updateOb(int r, int c, int row, int col);
  bool checkBoard();

  bool move(bool player, int r, int c, int row, int col, std::string type);

  bool moveRight(int r, int c, int col);
  bool moveLeft(int r, int c, int col);
  bool moveUp(int r, int c, int col);
  bool moveDown(int r, int c, int col);
  bool movePiece(int r, int c, int row, int col, std::string type);

  bool moveKnight(int r, int c, int row, int col);
  bool movePawn(int r, int c, int row, int col);

/* //tried to do undo method for it
  void undo(int r, int c, int row, int col, std::string mover, bool moverC,
     const bool destC = false, const std::string dest = ""); */

  bool kingRight(int r, int c, int row, int col, std::pair<int, int> k, bool player);
  bool kingLeft(int r, int c, int row, int col, std::pair<int, int> k, bool player);

  bool moveKing(bool player, int r, int c, int row, int col);

  bool legalMove(int r, int c, int row, int col, std::string type, bool player);
  bool check(bool player, int row, int col, std::string type);
  bool incheck(bool player, int row, int col);
  bool checkMate(bool player);
  std::pair<int, int> findKing(bool colour);
  std::pair<int, int> findRook(bool colour, int row, int col, int h, int v);


  friend std::ostream &operator<<(std::ostream &out, const ChessBoard &b);
};

#endif
