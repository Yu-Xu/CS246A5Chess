#ifndef ROOK_H
#define ROOK_H
#include "piece.h"
#include <string>

class Rook: public Piece {
  bool first;

 public:
  Rook(ChessBoard* subject, bool colour, int row, int col);
  ~Rook();

  //void notify() override;
  bool legalMove(int row, int col) override;
  bool getFirst() const;
  void setFirst(bool first);
};
#endif
