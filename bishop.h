#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"
#include <string>

class Bishop: public Piece {

  public:
    Bishop(std::string &type, bool &colour, std::pair<int, int> &coord);
    Bishop(std::string &type, bool &colour, std::pair<int, int> &coord,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm);
    ~Bishop();

    //method for determining all the legal moves of piece
    void loadLegalMoves() override;

    //method for returning if the move is legal, within range?
    bool legalMove(std::pair<int, int> dest) override;
};
#endif
