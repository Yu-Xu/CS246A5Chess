#ifndef COMPUTERL1_H
#define COMPUTERL1_H
#include "player.h"
#include "computer.h"
#include <string>

class ComputerL1: public Computer {
  public:
    ComputerL1(std::string &name, bool &colour);
    ~ComputerL1();

    //override method in concrete CpuLvl1
    std::pair<std::pair<int, int>, std::pair<int, int>> getMove() override;

  //  std::vector<std::pair<int, int>> legalRange(int r, int c, std::string type, bool player) override;
  //  std::vector<std::pair<int, int>> computerMove(bool player, int r, int c, std::string type) override;

};
#endif
