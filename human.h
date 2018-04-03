#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human: public Player {

 public:
  Human(std::string name, bool colour);
  ~Human();

  std::pair<int, int> getLocation(std::string location);

  std::pair< std::pair<int, int>, std::pair<int, int> > makeAMove() override;

};
#endif
