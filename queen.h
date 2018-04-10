#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include <string>

class Queen: public Piece {
  //bool check;

 public:
  Queen(ChessBoard* subject, bool colour, int row, int col);
  ~Queen();

  //void notify() override;
  bool legalMove(int row, int col) override;
};
#endif
