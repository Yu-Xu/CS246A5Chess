#include "human.h"

using namespace std;

Human::Human(std::string &name, bool &colour):
  Player{name, colour} {}

Human::~Human() {}

pair<int, int> Human::convertCoord(string &location) {
  char row = location[1];
  char col = location[0];
  int r;
  int c;
  r = 8 - (row - '0');
  c = col - 'a';

  return make_pair(r, c);
}


pair<pair<int, int>, pair<int, int>> Human::getMove() {
  string from;
  string dest;
  cin >> from >> dest;
  pair<int, int> f = convertCoord(from);
  pair<int, int> d = convertCoord(dest);

  return make_pair(f, d);
}
