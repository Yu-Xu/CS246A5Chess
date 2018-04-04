#ifndef KING_H
#define KING_H
#include "piece.h"
#include <string>

class King: public Piece {
  bool firstMove;

  public:
    King(std::string &type, bool &colour, std::pair<int, int> &coord);
    King(std::string &type, bool &colour, std::pair<int, int> &coord,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm);
    King(std::string &type, bool &colour, std::pair<int, int> &coord,
      std::pair<int, int> &coord, std::vector<std::pair<int, int>> &lm,
      const bool &fm = true);
    ~King();


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
