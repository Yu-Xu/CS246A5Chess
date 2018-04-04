#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <memory>
#include "piece.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"

//abstract player class
class Player {
  //shared amongst all player objects (Human, Computer)
  //name
  std::string name;
  //the colour
  bool colour;

  public:
    //ctors
    Player(std::string &name, bool &colour);
    virtual ~Player();

    //pure virtual method for getting a move from either player
    virtual std::pair<std::pair<int, int>, std::pair<int, int>> getMove() = 0;

    //getters
    std::string getName();
    bool getColour();
};

#endif
