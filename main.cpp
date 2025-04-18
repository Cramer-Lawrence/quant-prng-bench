#include <iostream>

#include "libseed/include/SeedGenerator.h"

int main()
{
	SeedGenerator sg {};
	
	std::cout << "Implicit Seed: " << sg.generateImplicitSeed() << "\n";
	std::cout << "Entropy Seed: " << sg.generateEntropySeed() << "\n";
	std::cout << "Hashed Seed: " << sg.generateHashedSeed() << std::endl;
	
	return 0;
}
