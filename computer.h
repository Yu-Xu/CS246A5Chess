#ifndef COMPUTER_H
#define COMPUTER_H
#include "player.h"

class Computer: public Player {
  int level;

 public:
  Computer(bool colour);
  ~Computer();

  void setLevel(int l) override:
  std::vector<std::pair<int, int>> legalRange(int r, int c, std::string type, bool player) override;
  std::vector<std::pair<int, int>> computerMove(bool player, int r, int c, std::string type) override;

};
#endif
