#include <iostream>
#include <random>

int main()
{
	int randomNumber;
	std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6); // distribution in range [1, 6]
	randomNumber = dist6(rng);

	std::cout << "Random is: " << randomNumber << std::endl;
	std::cout << "Random is: " << dist6(rng) << std::endl;
	std::cout << "Random is: " << dist6(rng) << std::endl;
	std::cout << "Random is: " << dist6(rng) << std::endl;
	std::cout << "Random is: " << dist6(rng) << std::endl;
	std::cout << "Random is: " << dist6(rng) << std::endl;

}