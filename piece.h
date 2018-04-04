#ifndef PIECE_H
#define PIECE_H
#include <string>
#include "Subject.h"
#include "observer.h"

class Piece {
  std::string type;  // See above
  bool colour;   // What colour was the new piece?  (NOT what is my colour)
  int r, c;
  bool check;

  public:
    Piece(std::string &t, bool &colour, int &row, int &col);
    Piece(const Piece &rhs);
    ~Piece();

    std::string getType();
    bool getColour();

    //void notify(bool player, int r, int c) override;
    virtual bool legalMove(bool player, int row, int col);
    virtual bool getPassant();
    virtual bool getFirst();
    virtual void setPassant(bool passant);
    virtual void setFirst(bool first);
    void print();
};

#endif
