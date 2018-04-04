#ifndef KING_H
#define KING_H
#include "piece.h"
#include <string>

class King: public Piece {
  bool first;

 public:
  King(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col);
  ~King();

  void notify() override;
  bool legalMove(int row, int col) override;
  bool getFirst() const;
  void setFirst(bool first);
};
#endif
