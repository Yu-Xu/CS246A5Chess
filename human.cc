#include "human.h"

using namespace std;

Human::Human(std::string &name, bool &colour):
  Player{name, colour} {}

Human::~Human() {}

std::pair<std::pair<int, int>, std::pair<int, int>> Human::getMove() {
  string from;
  string dest;
  cin >> from >> dest;
  pair<int, int> f = game.getLocation(from);
  pair<int, int> d = game.getLocation(dest);
  int r = f.first;
  int c = f.second;
  int row = d.first;
  int col = d.second;

  bool tryMove = game.move(turn, r, c, row, col);
  if (!tryMove) {
    cout << "Illegal Move" << endl;
    cout << "Please Try Again" << endl;
    continue;
  } else {

  }
}
