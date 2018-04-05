#ifndef COMPUTERL2_H
#define COMPUTERL2_H
#include "player.h"
#include "computer.h"
#include <string>

class ComputerL2: public Computer {
  public:
    ComputerL2(std::string &name, bool &colour);
    ~ComputerL2();

    //override method in concrete CpuLvl1
    std::pair<std::pair<int, int>, std::pair<int, int>> getMove() override;

  //  std::vector<std::pair<int, int>> legalRange(int r, int c, std::string type, bool player) override;
  //  std::vector<std::pair<int, int>> computerMove(bool player, int r, int c, std::string type) override;

};
#endif
