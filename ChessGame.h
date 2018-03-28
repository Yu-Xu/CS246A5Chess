#ifndef CHESSG_H
#define ChessGame_H
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include "ChessBoard.h"
#include "player.h"

class ChessGame {
  ChessBoard theBoard;
  Player p1;
  Player p2;

 public:
  ChessGame();
  ~ChessGame();

  void startGame(std::string player1, std::string player2);
  void remove(bool player, std::string type, int r, int c);
  bool checkMate(bool player);
  bool setUp(std::string command, std::string coordinate, std::string t);
  void setUpOb();
  void updateOb(int row, int col);

  //update pieces in the player
  bool move(bool player, int r, int c, int row, int col);
  void add(bool player, std::string type, int row, int col);
  void updatePlayer(bool player, int r, int c, int row, int col, std::string t1, std::string t2);

  std::vector<int> updatePiece(bool player);
  std::pair<int, int> getLocation(std::string location);

  friend std::ostream &operator<<(std::ostream &out, const ChessGame &g);
};

#endif
