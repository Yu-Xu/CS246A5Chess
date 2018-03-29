#ifndef FIRST_LEVEL
#define FIRST_LEVEL
#include "computer.h"

class FirstLevel: public Computer{
public:

	FirstLevel(bool color);
	~FirstLevel();

	std::vector< std::pair< int, int > > firstLevel(int r, int c);
	bool move(std::vector< std::pair< int, int > > moves);

};
#endif
