#include "human.h"
#include <string>

Human::Human(std::string name, bool colour): Player{name, colour} {}

Human::~Human() {}

std::pair<int, int> Human::getLocation(std::string location) {
  char row = location[1];
  char col = location[0];
  int r;
  int c;
  r = 8 - (row - '0');
  c = col - 'a';
  return std::pair<int, int>(r, c);
}

std::pair< std::pair<int, int>, std::pair<int, int> > Human::makeAMove()
{
	std::string from;
    std::string to;
    std::cin >> from >> to;
    std::pair<int, int> moveFrom = getLocation(from);
    std::pair<int, int> moveTo = getLocation(to);
	return std::pair< std::pair<int, int>, std::pair<int, int> >(moveFrom, moveTo);
}
