#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <utility>

//abstract player class
class Player {

  //name
  std::string name;
  //the colour
  bool colour;

  public:
    //ctors
    Player();
    Player(std::string &name, bool &colour);
    virtual ~Player();

    //pure virtual method for getting a move from either player
    virtual std::pair<std::pair<int, int>, std::pair<int, int>> getMove() = 0;

    //getters
    std::string getName();
    bool getColour();
};

#endif
