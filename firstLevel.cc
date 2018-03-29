#include "firstLevel.h"
#include "random"

FirstLevel::FirstLevel(bool color): Computer{color} {}

FirstLevel::~FirstLevel() {}

void FirstLevel::setLevel(int l) {
	this->level = 1;
}

std::vector<std::pair<int, int>> FirstLevel::legalRange(int r, int c, std::string type, bool player)
{

}

std::vector<std::pair<int, int>> FirstLevel::computerMove(bool player, int r, int c, std::string type)
{
	
}

std::vector< std::pair< int, int > > FirstLevel::firstLevel(int r, int c)
{

}

bool FirstLevel::move(std::vector< std::pair< int, int > > moves)
{

}

int main()
{

	std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]

    std::cout << dist6(rng) << std::endl;
	return 0;
}