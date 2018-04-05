#ifndef CHESSGAME_H
#define CHESSGAME_H
#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include "ChessBoard.h"
#include "player.h"
#include "Human.h"
#include "Computer.h"

//class that represents a single session of a game
class ChessGame {
  //a game requires a board and 2 Players
  ChessBoard theBoard;
  //the players own the pieces
  std::unique_ptr<Player> p1;
  std::unique_ptr<Player> p2;

  //count score
  double wScore, bScore;
  //determine turn
  bool turn, setBoard;

  //private methods for converting inputs for setup mode
  std::pair<int, int> convertCoord(std::string &location);
  std::pair<bool, char> convertPieceType(std::string &pType);

   public:
    ChessGame();
    ~ChessGame();

    //and a method that starts a setup game????
    //method for setup mode, loops until done command
    void setUpMode();

    //require a method that starts a new normal game
    //or starts the game with a custom set board if it was setup
    void startGame(std::string &p1, std::string &p2);

    //after setup the board, calls this and plays the setup board
    //don't need anymore
    //void playSetup();

    //method that checks for checkMate??
    //bool checkMate(bool colour);

    //update pieces in the player, maybe need these
    /*bool move(bool player, int r, int c, int row, int col);
    void add(bool player, std::string type, int row, int col);
    void updatePlayer(bool player, int r, int c, int row, int col, std::string t1, std::string t2);
    */

    //setters? prob dont need
    //void setTurn();
    //void setBoard();

    //getters
    double getWScore();
    double getBScore();
    bool getTurn();
    bool getSetB();

    friend std::ostream &operator<<(std::ostream &out, const ChessGame &g);
};

#endif
