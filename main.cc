#include <iostream>
#include "ChessGame.h"

using namespace std;

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);

  string cmd;
  ChessGame game;

  try {
    while (cin >> cmd) {
      if (cmd == "setup") { //setup mode
				//call game setup method
				game.setUpMode();

				//if setup, then u just do game and play with setup board
				//game.playSetup();

        cout << game;
      } else if (cmd == "game") { //play game, whether setup board or not
				string p1;
				string p2;
				while (cin >> p1 >> p2) {
					if ((p1 == "human" || p1 == "computer1" || p1 == "computer2" ||
						p1 == "computer3" || p1 == "computer4") &&
						(p2 == "human" || p2 == "computer1" || p2 == "computer2" ||
						p2 == "computer3" || p2 == "computer4")) {
							game.startGame(p1, p2);
					} else {
						cout << "Hey! You are not inputting correctly..." << endl;
						cout << "Options:" << endl;
						cout << "1. human" << endl;
						cout << "2. computer[1...4] (without the brackets)" << endl;
					}
				}
      }
    }
		cout << "Final Scores" << endl;
		cout << "White: " << game.getWScore() << endl;
		cout << "Black: " << game.getBScore() << endl;
  } catch (ios::failure &) {}  // Any I/O failure quits
	return 0;
}
