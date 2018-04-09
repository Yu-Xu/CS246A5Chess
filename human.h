#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"
#include <string>
#include <utility>

class Human: public Player {

  std::pair<int, int> convertCoord(std::string &location);

  public:
    Human(std::string &name, bool &colour);
    ~Human();

    //pure virtual method for getting a move from either player
    std::pair<std::pair<int, int>, std::pair<int, int>> getMove() override;

};
#endif
