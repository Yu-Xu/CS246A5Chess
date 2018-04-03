#ifndef PIECE_H
#define PIECE_H
#include <string>
#include "Subject.h"
#include "observer.h"

struct Piece: public Subject, public Observer  {
  std::string type;  // See above
  bool colour;   // What colour was the new piece?  (NOT what is my colour)
  int r, c;
  bool check;

  Piece(std::string t, bool colour, int row, int col);
  ~Piece() override;

  void notify(bool player, int r, int c, std::string type, std::vector<std::pair<int, int>> &v) override;
  virtual bool legalMove(int row, int col) = 0;
  virtual bool getPassant();
  virtual bool getFirst();
  virtual void setPassant(bool passant);
  virtual void setFirst(bool first);
  void print() override;
};

#endif
