#ifndef PAWN_H
#define PAWN_H
#include "piece.h"
#include <iostream>
#include <string>

class Pawn: public Piece {
  bool firstMove;
  bool enPassant;

  public:
    Pawn(std::string &type, bool &colour, std::pair<int, int> &coord);
    Pawn(std::string &type, bool &colour, std::pair<int, int> &coord,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm);
    Pawn(std::string &type, bool &colour, std::pair<int, int> &coord,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm,
      const bool &fm = true);
    Pawn(std::string &type, bool &colour, std::pair<int, int> &coord,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm,
      const bool &fm = true, const bool &enPas = false);
    ~Pawn();


    //method for determining all the legal moves of piece
    void loadLegalMoves() override;

    //method for returning if the move is legal, within range?
    bool legalMove(std::pair<int, int> dest) override;

    //getter for firstMove
    bool getFirst();
    //changes firstMove to false after moving for the first time
    void moved();
};
#endif
