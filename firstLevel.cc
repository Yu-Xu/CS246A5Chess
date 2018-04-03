#include "firstLevel.h"
#include "random"

FirstLevel::FirstLevel(std::string name, bool color): Computer{name, color, 1} {}

FirstLevel::~FirstLevel() {}


// std::vector<std::pair<int, int>> FirstLevel::legalRange(int r, int c, std::string type, bool player)
// {

// }

// std::vector<std::pair<int, int>> FirstLevel::computerMove(bool player, int r, int c, std::string type)
// {
	
// }

// std::vector< std::pair< int, int > > FirstLevel::firstLevel(int r, int c)
// {

// }

// bool FirstLevel::move(std::vector< std::pair< int, int > > moves)
// {

// }

std::pair< std::pair<int, int>, std::pair<int, int> > FirstLevel::makeAMove()
{
	std::cout << "Are we here homie?" << std::endl;
	return std::pair< std::pair< int, int >, std::pair< int, int > >();
}

std::pair< std::pair< int, int >, std::pair< int, int > > FirstLevel::calculateNextMove()
{
	std::cout << "We FINALLY got here god dammit" << std::endl;
	int randomNumber;
	std::pair<int, int> toMoveFrom, toMoveTo;
	//std::pair< std::pair< int, int>, std::pair< int, int> > result; 
	std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
	randomNumber = dist6(rng);
	switch(randomNumber)
	{
		case 1:
		{
			auto pawns = getPawns();
			int numOfPawns = pawns.size();
			if(numOfPawns > 0)
			{
				std::uniform_int_distribution<std::mt19937::result_type> distPawnSize(1,numOfPawns);
				toMoveFrom = pawns.at(distPawnSize(rng)); //Choose a random pawn to move
				std::uniform_int_distribution<std::mt19937::result_type> dist2(1,2);
				int newRandomNum = dist2(rng); //Choose how many squares to move
				toMoveTo = std::pair<int, int>(toMoveFrom.first, toMoveFrom.second + newRandomNum);
				return std::pair< std::pair< int, int>, std::pair< int, int> >(toMoveFrom, toMoveTo);
			}
			
			break;
		}
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
	}
	return std::pair< std::pair< int, int>, std::pair< int, int> >();
}
