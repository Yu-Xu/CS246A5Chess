#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include <iostream>

class Pawn: public Piece {
  bool first;
  bool passant;

 public:
  Pawn(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col);
  ~Pawn();

  //void notify() override;
  bool legalMove(int destinationRow, int destinationCol) override;
  bool getPassant() const;
  bool getFirst() const;
  void setPassant(bool passant);
  void setFirst(bool first);
};
#endif
