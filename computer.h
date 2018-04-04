#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"
#include <string>

class Computer: public Player {
  public:
    Computer(std::string &name, bool &colour);
    ~Computer();

  //  std::vector<std::pair<int, int>> legalRange(int r, int c, std::string type, bool player) override;
  //  std::vector<std::pair<int, int>> computerMove(bool player, int r, int c, std::string type) override;

};
#endif
