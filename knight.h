#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"
#include <string>

class Knight: public Piece {
  //bool check;

  public:
    Knight(std::string &type, bool &colour, std::pair<int, int> &coord);
    Knight(std::string &type, bool &colour, std::pair<int, int> &coord,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm);
    ~Knight();

    //method for determining all the legal moves of piece
    void loadLegalMoves() override;

    //method for returning if the move is legal, within range?
    bool legalMove(std::pair<int, int> dest) override;
};
#endif
