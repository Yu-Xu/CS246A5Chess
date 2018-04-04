#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <utility>
#include <memory>
#include <vector>
#include "Subject.h"
#include "observer.h"

//abstract piece class
// all pieces have their typename
// boolean colour (W,B) true=W false=B
// location(std::pair) current location
// Vector of Pairs for coordinates that they can move to
class Piece {
  std::string type;  // See above
  bool colour;   // What colour was the new piece?  (NOT what is my colour)
  std::pair<int, int> coord;
  std::vector<std::pair<int, int>> legalMoves;

  public:
    Piece(std::string &type, bool &colour, std::pair<int, int> &coord);
    Piece(std::string &type, bool &colour,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm);
    Piece(const Piece &p);
    Piece(const Piece &&p);
    Piece &operator=(const Piece &rhs);
    Piece &operator=(const Piece &&rhs);
    ~Piece();

    //virtual method for rules of the 6 pieces
    //finds all legal moves currently
    virtual void loadLegalMoves() = 0;

    //is move legal
    virtual bool legalMove(std::pair<int, int> dest) = 0;

    //getters
    bool getColour();
    std::string getType();
    std::pair<int, int> getCoord();
    std::vector<std::pair<int, int>> getMoves();
};

#endif
