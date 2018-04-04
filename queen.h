#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"
#include <string>

class Queen: public Piece {

  public:
    Queen(std::string &type, bool &colour, std::pair<int, int> &coord);
    Queen(std::string &type, bool &colour, std::pair<int, int> &coord,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm);
    ~Queen();

    //method for determining all the legal moves of piece
    void loadLegalMoves() override;

    //method for returning if the move is legal, within range?
    bool legalMove(std::pair<int, int> dest) override;


};
#endif
