#ifndef KING_H
#define KING_H
#include "piece.h"
#include <string>

class King: public Piece {
  bool first;

 public:
  King(std::string s, bool colour, int row, int col);
  ~King();

  bool legalMove(int row, int col) override;
  bool getFirst() override;
  void setFirst(bool first) override;
};
#endif
