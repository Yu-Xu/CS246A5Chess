#include "firstLevel.h"
#include <random>

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

//This method just calls the calculateNextMove
std::pair< std::pair<int, int>, std::pair<int, int> > FirstLevel::makeAMove()
{
	return calculateNextMove();
	//return std::pair< std::pair< int, int >, std::pair< int, int > >();
}

//This method will return a random move by the rules but won't know whether there are pieces in the way that prevent it or if it's outside
//So needs to be called again if move is incorrect
std::pair< std::pair< int, int >, std::pair< int, int > > FirstLevel::calculateNextMove()
{
	int randomNumber;
	std::pair<int, int> toMoveFrom, toMoveTo;
	//std::pair< std::pair< int, int>, std::pair< int, int> > result; 
	std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
	randomNumber = dist6(rng);
	std::cout << "Random number is " << randomNumber << std::endl;
	while(true) //The infinite loop will be escaped by the return
	{
		switch(randomNumber)
		{
			case 1:
			{
				auto pawns = getPawns();
				int numOfPawns = pawns.size();
				if(numOfPawns > 0)
				{
					std::uniform_int_distribution<std::mt19937::result_type> distPawnSize(1,numOfPawns);
					toMoveFrom = pawns.at(distPawnSize(rng) - 1); //Choose a random pawn to move
					//std::cout << "toMoveFrom in pawn is " << toMoveFrom.first << ", " << toMoveFrom.second << std::endl;
					std::uniform_int_distribution<std::mt19937::result_type> dist2(1,2);
					int newRandomNum = dist2(rng); //Choose how many squares to move
					if(getColour() == 1)
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first - newRandomNum, toMoveFrom.second);

					}
					else
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first + newRandomNum, toMoveFrom.second);
					}
					return std::pair< std::pair< int, int>, std::pair< int, int> >(toMoveFrom, toMoveTo);
				}
				break;
			}
			case 2:
			{
				auto rooks = getRooks();
				int numOfRooks = rooks.size();
				if(numOfRooks > 0)
				{
					std::uniform_int_distribution<std::mt19937::result_type> distRookSize(1,numOfRooks);
					toMoveFrom = rooks.at(distRookSize(rng) - 1); //Choose a random rook to move
					std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7);
					std::uniform_int_distribution<std::mt19937::result_type> dist4(1,4);
					int newRandomNum = dist7(rng); //Choose how many squares to move
					int randomDirection = dist4(rng); //Choose a direction
					if(randomDirection == 1) //Up
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first - newRandomNum, toMoveFrom.second);
					}
					else if(randomDirection == 2) //Right
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first, toMoveFrom.second + newRandomNum);
					}
					else if(randomDirection == 3) //Down
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first + newRandomNum, toMoveFrom.second);
					}
					else if(randomDirection == 4) //Left
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first, toMoveFrom.second - newRandomNum);
					}
					return std::pair< std::pair< int, int>, std::pair< int, int> >(toMoveFrom, toMoveTo);
				}
				break;
			}
			case 3:
			{
				auto bishops = getBishops();
				int numOfBishops = bishops.size();
				if(numOfBishops > 0)
				{
					std::uniform_int_distribution<std::mt19937::result_type> distBishopSize(1,numOfBishops);
					toMoveFrom = bishops.at(distBishopSize(rng) - 1); //Choose a random bishop to move
					std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7);
					std::uniform_int_distribution<std::mt19937::result_type> dist4(1,4);
					int newRandomNum = dist7(rng); //Choose how many squares to move
					int randomDirection = dist4(rng); //Choose a direction
					if(randomDirection == 1) //Up-Right
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first - newRandomNum, toMoveFrom.second + newRandomNum);
					}
					else if(randomDirection == 2) //Down-Right
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first + newRandomNum, toMoveFrom.second + newRandomNum);
					}
					else if(randomDirection == 3) //Down-Left
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first + newRandomNum, toMoveFrom.second - newRandomNum);
					}
					else if(randomDirection == 4) //Up-Left
					{
						toMoveTo = std::pair<int, int>(toMoveFrom.first - newRandomNum, toMoveFrom.second - newRandomNum);
					}
					return std::pair< std::pair< int, int>, std::pair< int, int> >(toMoveFrom, toMoveTo);
				}
				break;
			}
			case 4:
			{
				auto knights = getKnights();
				int numOfKnights = knights.size();
				if(numOfKnights > 0)
				{
					std::uniform_int_distribution<std::mt19937::result_type> distKnightSize(1,numOfKnights);
					toMoveFrom = knights.at(distKnightSize(rng) - 1); //Choose a random knight to move
					std::uniform_int_distribution<std::mt19937::result_type> dist4(1,4);
					std::uniform_int_distribution<std::mt19937::result_type> dist2(1,2);
					int randomSide = dist2(rng); //Choose which side to move
					int randomDirection = dist4(rng); //Choose a direction
					if(randomDirection == 1) //Up
					{
						if(randomSide == 1) //Left
						{
							toMoveTo = std::pair<int, int>(toMoveFrom.first - 1, toMoveFrom.second + 2);
						}
						else //RIght
						{
							toMoveTo = std::pair<int, int>(toMoveFrom.first + 1, toMoveFrom.second + 2);
						}
						
					}
					else if(randomDirection == 2) //Right
					{
						if(randomSide == 1) //Left
						{
							toMoveTo = std::pair<int, int>(toMoveFrom.first + 2, toMoveFrom.second + 1);
						}
						else //RIght
						{
							toMoveTo = std::pair<int, int>(toMoveFrom.first + 2, toMoveFrom.second - 1);
						}					}
					else if(randomDirection == 3) //Down
					{
						if(randomSide == 1) //Left (which looks more like Down-Right)
						{
							toMoveTo = std::pair<int, int>(toMoveFrom.first + 1, toMoveFrom.second - 2);
						}
						else //RIght
						{
							toMoveTo = std::pair<int, int>(toMoveFrom.first - 1, toMoveFrom.second - 2);
						}
					}
					else if(randomDirection == 4) //Left
					{
						if(randomSide == 1) //Left
						{
							toMoveTo = std::pair<int, int>(toMoveFrom.first - 2, toMoveFrom.second - 1);
						}
						else //RIght
						{
							toMoveTo = std::pair<int, int>(toMoveFrom.first - 2, toMoveFrom.second + 1);
						}					
					}
					return std::pair< std::pair< int, int>, std::pair< int, int> >(toMoveFrom, toMoveTo);
				}
				break;
			}
			case 5:
			{
				auto king = getKing();
				std::uniform_int_distribution<std::mt19937::result_type> dist8(1,8);
				int newRandomNumber = dist8(rng);
				toMoveFrom = king.at(0);
				if(newRandomNumber == 1)
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first - 1, toMoveFrom.second + 1);
				}
				else if(newRandomNumber == 2)
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first, toMoveFrom.second + 1);
				}
				else if(newRandomNumber == 3)
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first + 1, toMoveFrom.second + 1);
				}
				else if(newRandomNumber == 4)
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first - 1, toMoveFrom.second);
				}
				else if(newRandomNumber == 5)
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first + 1, toMoveFrom.second);
				}
				else if(newRandomNumber == 6)
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first - 1, toMoveFrom.second - 1);
				}
				else if(newRandomNumber == 7)
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first, toMoveFrom.second - 1);
				}
				else if(newRandomNumber == 8)
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first + 1, toMoveFrom.second - 1);
				}
				return std::pair< std::pair< int, int>, std::pair< int, int> >(toMoveFrom, toMoveTo);
				break;
			}
			case 6:
			{
				auto queen = getQueen();
				std::uniform_int_distribution<std::mt19937::result_type> dist8(1,8);
				std::uniform_int_distribution<std::mt19937::result_type> dist7(1,7);
				int newRandomNumber = dist8(rng);
				int randomNumberOfSquares = dist7(rng);
				toMoveFrom = queen.at(0);
				if(newRandomNumber == 1) //Up-Left
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first - randomNumberOfSquares, toMoveFrom.second + randomNumberOfSquares);
				}
				else if(newRandomNumber == 2) //Up
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first, toMoveFrom.second + randomNumberOfSquares);
				}
				else if(newRandomNumber == 3) //Up-right
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first + randomNumberOfSquares, toMoveFrom.second + randomNumberOfSquares);
				}
				else if(newRandomNumber == 4) //Left
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first - randomNumberOfSquares, toMoveFrom.second);
				}
				else if(newRandomNumber == 5) //Right
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first + randomNumberOfSquares, toMoveFrom.second);
				}
				else if(newRandomNumber == 6) //Down-Left
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first - randomNumberOfSquares, toMoveFrom.second - randomNumberOfSquares);
				}
				else if(newRandomNumber == 7) //Down
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first, toMoveFrom.second - randomNumberOfSquares);
				}
				else if(newRandomNumber == 8) //Down-Right
				{
					toMoveTo = std::pair<int, int>(toMoveFrom.first + randomNumberOfSquares, toMoveFrom.second - randomNumberOfSquares);
				}
				return std::pair< std::pair< int, int>, std::pair< int, int> >(toMoveFrom, toMoveTo);
				break;
			}
		}
		//We shouldn't reach here
		//return std::pair< std::pair< int, int>, std::pair< int, int> >();
	}
	
}
