#include <iostream>

#include "timer.h"
#include "libseed/include/SeedGenerator.h"
#include "BenchReport.h"

int main()
{
	libbench::Timer t {"main"}; // sets up benchmark timer
	SeedGenerator sg {}; // sets up SeedGenerator
	
	std::cout << "Implicit Seed:\n";
	std::cout << sg.generateImplicitSeed() << "\n\n";
	std::cout << "Entropy Seed:\n";
	std::cout << sg.generateEntropySeed() << "\n\n";
	std::cout << "Hashed Seed:\n";
	std::cout << sg.generateHashedSeed() << "\n" << std::endl;
	
	//BenchReport::endLog();
	return 0;
}
