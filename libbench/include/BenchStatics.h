#ifndef BENCHSTATICS_H
#define BENCHSTATICS_H

#include <string>
#include <vector>
#include <utility>
#include <cstdint>

class BenchStatics
{
public:
	static std::vector<std::pair<uint64_t, int>> calculateDistribution(std::vector<uint64_t> inVec, const std::string& reportTypeMsg);

	static void generateDistributionRatio(std::vector<std::pair<uint64_t, int>> distVec, const std::string& reportTypeMsg);

private:
	template<typename T>
	static int checkVectorForValue(std::vector<T>& checkVector, const T& searchValue)
	{
		for (int i = 0; i < checkVector.size(); ++i)
		{
			if (checkVector[i] == searchValue)
			{
				return i;
			}
		}
		return -1;
	}

	template<typename T, typename U>
	static int checkVectorForValue(std::vector<std::pair<T, U>> checkVector, const T& searchValue)
	{
		for (int i = 0; i < checkVector.size(); ++i)
		{
			if (checkVector[i].first == searchValue)
			{
				return i;
			}
		}
		return -1;
	}
};

#endif
