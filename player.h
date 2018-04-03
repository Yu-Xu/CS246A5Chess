#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "piece.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"


class Player {
  std::string name;
  bool colour;

  std::vector<std::pair<int, int>> queen;
  std::vector<std::pair<int, int>> king;
  std::vector<std::pair<int, int>> knights;
  std::vector<std::pair<int, int>> bishops;
  std::vector<std::pair<int, int>> rooks;
  std::vector<std::pair<int, int>> pawns;

  public:
  Player(bool colour);
  Player(std::string name, bool colour);
  virtual ~Player();
  std::vector<std::pair<int, int>> &getRooks();
  std::vector<std::pair<int, int>> &getBishops();
  std::vector<std::pair<int, int>> &getKnights();
  std::vector<std::pair<int, int>> &getPawns();
  std::vector<std::pair<int, int>> &getKing();
  std::vector<std::pair<int, int>> &getQueen();
  void setPlayerName(std::string name);
  std::string getPlayerName();
  virtual void setLevel(int l);
  bool getColour();
  
  virtual std::pair< std::pair<int, int>, std::pair<int, int> > makeAMove(); //Maybe make pure virtual
};

#endif
