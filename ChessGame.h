#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <memory>
#include "ChessBoard.h"
#include "player.h"
#include "human.h"
#include "firstLevel.h"

class ChessGame {
  ChessBoard theBoard;
  // Player p1;
  // Player p2;
  std::unique_ptr<Player> p1;
  std::unique_ptr<Player> p2;

  //std::vector<std::unique_ptr<Player> > players;

 public:
  ChessGame();
  ~ChessGame();

  void startGame(std::string player1, std::string player2);
  void remove(bool player, std::string type, int r, int c);
  bool checkMate(bool player);
  bool setUp(std::string command, std::string coordinate, std::string t);
  void setUpOb();
  void updateOb(int row, int col);

  Player* getPlayer1();
  Player* getPlayer2();

  //update pieces in the player
  bool move(bool player, int r, int c, int row, int col);
  void add(bool player, std::string type, int row, int col);
  void updatePlayer(bool player, int r, int c, int row, int col, std::string t1, std::string t2);

  std::vector<int> updatePiece(bool player);
  std::pair<int, int> getLocation(std::string location);

  friend std::ostream &operator<<(std::ostream &out, const ChessGame &g);
};

#endif
