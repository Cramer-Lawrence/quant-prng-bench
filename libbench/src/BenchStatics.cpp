#include "BenchStatics.h"

#include <bits/stdc++.h>

#include "BenchReport.h"


std::vector<std::pair<uint64_t, int>> BenchStatics::calculateDistribution(std::vector<uint64_t> inVec, const std::string& reportTypeMsg) {
  
	std::vector<std::pair<uint64_t, int>> outVec{};
	
	BenchReport::log("Generating " + reportTypeMsg + " Distribution Report...");

  for (const uint64_t &i : inVec) {
    int n { checkVectorForValue(outVec, i) };
    if ( n == -1)
    {
      outVec.push_back({i, 1});
    }
    else
    {
      outVec[n].second++;
    }
  }

  std::sort(outVec.begin(), outVec.end());

  for (std::pair<const int, int> p : outVec) {
    BenchReport::log(std::to_string(p.first) 
		    + " - " 
		    + std::to_string(p.second));
  }

  BenchReport::log("Distribution Report Complete");

  return outVec;
}
