#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <memory>
#include "ChessBoard.h"
#include "player.h"

//class that represents a single session of a game
class ChessGame {
  //a game requires a board and 2 Players
  ChessBoard theBoard;
  //the players own the pieces
  std::unique_ptr<Player> p1;
  std::unique_ptr<Player> p2;

   public:
    ChessGame();
    ~ChessGame();
    //require a method that starts a new normal game
    void standardGame(std::string &p1, std::string &p2);

    //and a method that starts a setup game????
    //method for setup mode, loops until done command
    void setUpMode();

    //after setup the board, calls this and plays the setup board
    void playSetup();

    //method that checks for checkMate
    bool checkMate(bool colour);

    //update pieces in the player maybe need these
    /*bool move(bool player, int r, int c, int row, int col);
    void add(bool player, std::string type, int row, int col);
    void updatePlayer(bool player, int r, int c, int row, int col, std::string t1, std::string t2);
    */

    friend std::ostream &operator<<(std::ostream &out, const ChessGame &g);
};

#endif
