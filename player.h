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
#include "rock.h"


class Player {
  std::string player;
  bool colour;

  std::vector<std::pair<int, int>> queen;
  std::vector<std::pair<int, int>> king;
  std::vector<std::pair<int, int>> knights;
  std::vector<std::pair<int, int>> bishops;
  std::vector<std::pair<int, int>> rocks;
  std::vector<std::pair<int, int>> pawns;

  public:
  Player(bool colour);
  virtual ~Player();
  std::vector<std::pair<int, int>> &getRocks();
  std::vector<std::pair<int, int>> &getBishops();
  std::vector<std::pair<int, int>> &getKnights();
  std::vector<std::pair<int, int>> &getPawns();
  std::vector<std::pair<int, int>> &getKing();
  std::vector<std::pair<int, int>> &getQueen();
  void setPlayer(std::string p);
  virtual void setLevel(int l);
  bool getColour();
};

#endif