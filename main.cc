#include <iostream>
// You may include other allowed headers, as needed
#include "ChessGame.h"
using namespace std;

// Do not remove any code; do not add code other than where indicated.

int main(int argc, char *argv[]) {
  cin.exceptions(ios::eofbit|ios::failbit);
  bool turn = 1;
  bool h1 = true;
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
      } else if (cmd == "setup") {
        inSetup = true;
        cout << game;
      } else if (cmd == "+" && inSetup ==  true) {
        string t;
        string coordinate;
        cin >> t >> coordinate;
        game.setUp(cmd, coordinate, t);
        cout << game;
      } else if (cmd == "-" && inSetup ==  true) {
        string coordinate;
        cin >> coordinate;
        game.setUp(cmd, coordinate, "");
        cout << game;
      } else if (cmd == "done" && inSetup ==  true) {
        goodSetup = game.setUp(cmd, "", "");
        if (goodSetup == false) {
          cout << "Illegal Setup" << endl;
          cout << "Do some changes" << endl;
        } else {
          cout << game;
          ifSetup = true;
          inSetup = false;
        }
      } else if (cmd == "game") {
        if (ifSetup ==  false) {
          cin >> p1 >> p2;
          game.startGame(p1, p2);
          if(p1 != "human") h1 = false;
          if(p2 != "human") h2 = false;
        }
        cout << game;
      }  else if (cmd == "move") {
        if(turn == 1 && !h1) {
          // game.computerMove(turn);
          std::cout << "Name is: " << game.getPlayer1()->getPlayerName() << std::endl;
          int r,c,row,col;

          // auto moveFromTo = game.getPlayer1()->makeAMove();
          //   std::cout << moveFromTo.first.first << ", " << moveFromTo.first.second << " to " << moveFromTo.second.first << ", " << moveFromTo.second.second << std::endl;

          //   r = moveFromTo.first.first;
          //   c = moveFromTo.first.second;
          //   row = moveFromTo.second.first;
          //   col = moveFromTo.second.second;
          do
          {
            auto moveFromTo = game.getPlayer1()->makeAMove();
            std::cout << moveFromTo.first.first << ", " << moveFromTo.first.second << " to " << moveFromTo.second.first << ", " << moveFromTo.second.second << std::endl;

            r = moveFromTo.first.first;
            c = moveFromTo.first.second;
            row = moveFromTo.second.first;
            col = moveFromTo.second.second;
          }
          while(!game.move(turn, r, c, row, col));
          

          //std::pair<std::pair<int, int>, std::pair<int, int> > moveFromTo ;
          // for (int i = 0; i < 10; ++i)
          // {
          //   moveFromTo = game.getPlayer1()->makeAMove();
          //   std::cout << moveFromTo.first.first << ", " << moveFromTo.first.second << " to " << moveFromTo.second.first << ", " << moveFromTo.second.second << std::endl;
          // }
          //game.getPlayer1()->makeAMove();
          //Delete next three lines
          // int temp;
          // std::cout << "Freeeze:";
          // std::cin >> temp;
        }
        else if(turn == 0 && !h2) {
          //game.computerMove(turn);
        }
        else if(turn == 1 && h1) {
          // string from;
          // string dest;
          // cin >> from >> dest;
          // std::pair<int, int> f = game.getLocation(from);
          // std::pair<int, int> d = game.getLocation(dest);
          // int r = f.first;
          // int c = f.second;
          // int row = d.first;
          // int col = d.second;
          int r,c,row,col;
          auto moveFromTo = game.getPlayer1()->makeAMove();
          r = moveFromTo.first.first;
          c = moveFromTo.first.second;
          row = moveFromTo.second.first;
          col = moveFromTo.second.second;
          if (!game.move(turn, r, c, row, col)) {
            cout << "Ilegal Move" << endl;
            cout << "Please Try Again" << endl;
            continue;
          }
        }
        else if(turn == 0 && h2)
        {
          int r,c,row,col;
          auto moveFromTo = game.getPlayer2()->makeAMove();
          r = moveFromTo.first.first;
          c = moveFromTo.first.second;
          row = moveFromTo.second.first;
          col = moveFromTo.second.second;
          if (!game.move(turn, r, c, row, col)) {
            cout << "Ilegal Move" << endl;
            cout << "Please Try Again" << endl;
            continue;
          }
        }
        // staleMate = game.staleMate();
        checkMate = game.checkMate(turn);
        // if (staleMate ==  true) {
        //   cout << "Draw" << endl;
        //   wScore += 0.5;
        //   bScore += 0.5;
        // } else
        if (checkMate ==  true) {
          if (turn == true) {
            wScore += 1;
            cout << "White Wins" << endl;
          } else {
            bScore += 1;
            cout << "Black Wins" << endl;
          }
        }
        if (turn == 1) {
          turn = 0;
        } else {
          turn = 1;
        }
        cout << game;
      }
    }
  }
  catch (ios::failure &) {}  // Any I/O failure quits

}
