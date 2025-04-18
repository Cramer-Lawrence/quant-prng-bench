#ifndef SEEDGENERATOR_H
#define SEEDGENERATOR_H

#include <iostream>
#include <chrono>

class SeedGenerator 
{
public:
	SeedGenerator() = default;

	// generates a seed based on system clock milliseconds -> epoch
	const uint64_t generateImplicitSeed();

	// generates a seed derived from the process id 
	const uint64_t generateEntropySeed();

	// generates a seed based on a combination of Implicit and Entropy then hashes it
	const uint64_t generateHashedSeed();

private:
	uint64_t getImplicitEntropyCombination();
};

#endif
