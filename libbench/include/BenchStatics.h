#ifndef BENCHSTATICS_H
#define BENCHSTATICS_H

#include <cstdint>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class BenchStatics {
public:
  static std::unordered_map<uint64_t, int>
  calculateDistribution(const std::vector<uint64_t> &inVec,
                        const std::string &reportTypeMsg);

  static void
  generateDistributionRatio(std::unordered_map<uint64_t, int>& frequencyMap,
                            const std::string &reportTypeMsg);
};

#endif
