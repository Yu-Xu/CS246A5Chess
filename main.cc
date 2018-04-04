#include <iostream>
// You may include other allowed headers, as needed
#include "ChessGame.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  //whose turn it is
  bool turn = 1;
  //is player1 human
  bool h1 = true;
  //is player2 human
  bool h2 = true;

  bool goodSetup = true;
  bool inSetup = false;
  bool ifSetup = false;
  // bool staleMate = false;
  bool checkMate = false;
  int wScore = 0;
  int bScore = 0;
  string cmd;
  ChessGame game;
  string p1;
  string p2;
  try {
    while (cin >> cmd) {
      if (cin.eof()) {
        cout << "Final Scores" << endl;
        cout << "White: " << wScore << endl;
        cout << "Black: " << bScore << endl;
        break;
      } else if (cmd == "setup") { //setup mode


        inSetup = true;


        cout << game;
      } else if (cmd == "game") { //standard game

        if (ifSetup ==  false) {
          cin >> p1 >> p2;
          game.standardGame(p1, p2);

        }
        cout << game;
      }
    }
  } catch (ios::failure &) {}  // Any I/O failure quits

}
