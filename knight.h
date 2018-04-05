#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
#include <string>

class Knight: public Piece {
  //bool check;

 public:
  Knight(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col);
  ~Knight();

  //void notify() override;
  bool legalMove(int row, int col) override;
};
#endif
