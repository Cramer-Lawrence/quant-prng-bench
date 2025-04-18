#include "SeedGenerator.h"

// external
#include <unistd.h>
#include <openssl/sha.h>

//internal
#include "timer.h"

const uint64_t SeedGenerator::generateImplicitSeed()
{
	libbench::Timer t { "generateImplicitSeed" };

	auto time {std::chrono::system_clock::now()};
	return std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch()).count();
}

const uint64_t SeedGenerator::generateEntropySeed()
{
	libbench::Timer t { "generateEntropySeed" };

	return static_cast<int>(getpid());
}

uint64_t SeedGenerator::getImplicitEntropyCombination()
{
	return generateImplicitSeed() - generateEntropySeed();
}

const uint64_t SeedGenerator::generateHashedSeed()
{
	libbench::Timer t { "generateHashedSeed" };

	std::string combo {std::to_string(getImplicitEntropyCombination())};
	unsigned char hash[SHA256_DIGEST_LENGTH];
	SHA256(reinterpret_cast<const unsigned char*>(combo.c_str()), combo.size(), hash);
	return static_cast<uint64_t>(*hash);
}
