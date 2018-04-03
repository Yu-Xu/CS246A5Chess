#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
#include <string>

class Knight: public Piece {
  //bool check;

 public:
  Knight(std::string s, bool colour, int row, int col);
  ~Knight();

  bool legalMove(int row, int col) override;
};
#endif
