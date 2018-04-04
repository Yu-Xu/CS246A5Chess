#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "piece.h"

class Cell : public Subject<info, State>, public Observer<Info, State> {
  std::pair<int, int> cellLoc;
  bool tileColour;
  std::unique_ptr<Piece> p;

 public:
  Cell();
  ~Cell();

  void setCell(int r,int c,bool colour);
  Piece *&getPiece();
  void clearPiece();

  //bool movePiece(bool player, int row, int col);
  // Place a piece of given colour here.
  void setPiece(std::string s, bool colour);   

  void attackPiece(std::string s, bool colour);

  void notify(Subject<Info, State> &whoFrom) override;
  friend std::ostream &operator<<(std::ostream &out, const Cell &c);
};
#endif
