#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <string>

class Bishop: public Piece {
  //bool check;

 public:
  Bishop(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col);
  ~Bishop();

  //void notify() override;
  bool legalMove(int row, int col) override;
};
#endif
