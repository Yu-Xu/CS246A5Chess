#ifndef FIRST_LEVEL
#define FIRST_LEVEL
#include "computer.h"

class FirstLevel: public Computer{
public:

	FirstLevel(std::string name, bool color);
	~FirstLevel();

	std::vector< std::pair< int, int > > firstLevel(int r, int c);
	bool move(std::vector< std::pair< int, int > > moves);

	std::pair< std::pair<int, int>, std::pair<int, int> > makeAMove() override;
	std::pair< std::pair< int, int >, std::pair< int, int > > calculateNextMove() override;

};
#endif
