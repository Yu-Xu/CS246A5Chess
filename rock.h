#ifndef Rock_H
#define Rock_H
#include "piece.h"
#include <string>

class Rock: public Piece {
  bool first;

 public:
  Rock(std::string s, bool colour, int row, int col);
  ~Rock();

  bool legalMove(bool player, int row, int col) override;
  bool getFirst() override;
  void setFirst(bool first) override;
};
#endif
