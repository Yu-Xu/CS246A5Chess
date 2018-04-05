#include <string>
#include <iostream>
#include <utility>

#include "ChessGame.h"

using namespace std;

ChessGame::ChessGame():
  theBoard{ChessBoard{}},
  p1{make_unique<Player>()},
  p2{make_unique<Player>()},
  wScore{0}, bScore{0}, turn{true}, setBoard{false} {}

ChessGame::~ChessGame() {}

//get the coordinates from command for the piece to be set
pair<int, int> ChessGame::convertCoord(string &location) {
  char row = location[1];
  char col = location[0];
  int r;
  int c;
  r = 8 - (row - '0');
  c = col - 'a';

  return pair<int, int>(r, c);
}

//get the Piece to be set from command
pair<bool, char> ChessGame::convertPieceType(string &pType) {
  bool colour;
  char type = pType[0];

  if (type >= 'a' && type <= 'z') {
    colour = false;
  } else {
    colour = true;
  }

  return pair<bool, char>(colour, type);
}

//setup mode method, for setting up custom board
void ChessGame::setUpMode() {
  string cmd;

  try {
    while (cin >> cmd) {

      if (cmd == "+") {

        string type;
        string coordinate;

        cin >> type >> coordinate; //possibly do an input check here as well...

        pair<int, int> coord = convertCoord(coordinate);
        pair<bool, char> p = convertPieceType(type);

        //call a method, but don't know what yet
        // adding needs to check destination: taken or not

        /*
        if (theBoard.getBoard()[c.first][c.second].getPiece() != nullptr) {
          bool player = theBoard.getBoard()[c.first][c.second].getPiece()->colour;
          string t1 = theBoard.getBoard()[c.first][c.second].getPiece()->type;
          //this->remove(player, t1, c.first, c.second);
        }
        theBoard.addPiece(c.first, c.second, t, colour);
        //this->add(colour, t, c.first, c.second);
        */

        //game.setUp(cmd, coordinate, t);

        cout << game;
      } else if (cmd == "-") {

        string coordinate;
        cin >> coordinate;

        pair<int, int> coord = convertCoord(coordinate);

        //check if there is a piece at destination:
        // if so do the remove, else (empty) do nothing

        /*
        //this->remove(colour, t, c.first, c.second);
        theBoard.removePiece(c.first, c.second);
        */

        //game.setUp(cmd, coordinate, "");


        cout << game;
      } else if (cmd == "=") { //choose which colour goes first
        string colour;
        cin >> colour;
        if (colour == "white") {
          turn = true;
        } else if (colour == "black") {
          turn = false;
        } else {
          cout << "don't come here pls, you typed it wrong..." << endl;
        }
      } else if (cmd == "done") {

        //need to check board state:
        //1. check current king statuses
          // - either kings in check?
        //2. pawns not at the top or bottom rows
        //3. ???? profit
        //result = theBoard.checkBoard();

        /*
        if (goodSetup() == false) {

          cout << "Illegal Setup" << endl;
          cout << "Do some changes" << endl;
        } else {

          cout << game;
        }
        */

      } else {

        cout << "not a command, try again" << endl;
      }

    }//end of while

  } catch (ios::failure &) {}
}

//normal, standard game of chess
void ChessGame::startGame(string &p1, string &p2) {
  cin.exceptions(ios::eofbit|ios::failbit);

  //initialize the game board depending on whether board was set or not
  if (!setBoard) {
    theBoard.init();
  }

  //determine what kind of player for (W)
  if(p1 == "human") {
    p1 = make_unique<Human>("White", true);
  } else if (p1 == "computer1") {
    p1 = make_unique<ComputerL1>("White", true);
  } else if (p1 == "computer2") {
    p1 = make_unique<ComputerL2>("White", true);
  } else if (p1 == "computer3") {
    p1 = make_unique<ComputerL3>("White", true);
  } else {
    //p1 = make_unique<ComputerL4>("White", true);
  }

  //what kind of player for (B)
  if(p2 == "human") {
    p2 = make_unique<Human>("Black", false);
  } else if (p2 == "computer1") {
    p2 = make_unique<ComputerL1>("Black", false);
  } else if (p2 == "computer2") {
    p2 = make_unique<ComputerL2>("Black", false);
  } else if (p2 == "computer3") {
    p2 = make_unique<ComputerL3>("Black", false);
  } else {
    //p2 = make_unique<ComputerL4>("Black", false);
  }

  //input command
  string cmd;

  try {
    //standard game loop, get new move until end game conditions
    while (cin >> cmd) {
      if (cmd == "move") { //if command for move
        pair<int, int> temp;

        if (turn) { //white player's turn

          temp = p1->getMove();
          //do stuff

          turn = false;
        } else { //black player's turn

          temp = p2->getMove();
          //do stuff

          turn = true;
        }

        //print board
        cout << game;

        // staleMate = game.staleMate();
        // checkMate = checkMate(turn);

        //check for end game conditions
        /*
        if (checkMate) { //checkmate
          if (turn) { //who won just logic for now, might change
            wScore++;
            cout << "White Wins!" << endl;
          } else {
            bScore++;
            cout << "Black Wins!" << endl;
          }
          break;
        } else if (staleMate) { //stalemate
          wScore += 0.5;
          bScore += 0.5;
          cout << "Stalemate! +0.5 to both players." << endl;
          break;
        }
        */

      } else if (cmd == "resign") { //if a player resigns
        if (turn) {
          bScore++;
          cout << "White has resigned!" << endl << "Black Wins!" << endl;
        } else {
          wScore++;
          cout << "Black has resigned!" << endl << "White Wins!" << endl;
        }
        break;
      } else {
        cout << "not a command, try again" << endl;
      }
    }

    //clear the board? with a clearBoard method?
    //clearBoard();

  } catch (ios::failure &) {}  // Any I/O failure quit
}

//play the custom set board, might not need this now?? hmmmm
//void ChessGame::playSetup() {}

//getters
double ChessGame::getWScore() { return wScore; }
double ChessGame::getBScore() { return bScore; }
bool ChessGame::getTurn() { return turn; }
bool ChessGame::getSetB() { return setBoard; }

/*
bool ChessGame::checkMate(bool player) {
  return theBoard.checkMate(player);
}
*/

ostream &operator<<(ostream &out, const ChessGame &g) {
  out << g.theBoard;
  return out;
}
