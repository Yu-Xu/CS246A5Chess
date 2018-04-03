#include "computer.h"

Computer::Computer(std::string name, bool colour, int level): Player{name, colour}
, level{level} {}


Computer::~Computer() {}

// std::pair< std::pair<int, int>, std::pair<int, int> > Computer::makeAMove()
// {
// 	std::cout << "Are we here fam?" << std::endl;
// 	return calculateNextMove();
// }

std::pair< std::pair< int, int >, std::pair< int, int > > Computer::calculateNextMove()
{
	return std::pair< std::pair< int, int >, std::pair< int, int > >();
}

void Computer::setLevel(int l) {
  this->level = l;
}
