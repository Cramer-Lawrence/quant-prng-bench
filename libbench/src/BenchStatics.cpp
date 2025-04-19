#include "BenchStatics.h"

#include <algorithm>

#include "BenchReport.h"

std::unordered_map<uint64_t, int>
BenchStatics::calculateDistribution(const std::vector<uint64_t> &inVec,
                                    const std::string &reportTypeMsg) {

  std::unordered_map<uint64_t, int> frequencyMap;
  BenchReport::log("Generating " + reportTypeMsg + " Distribution Report...");

  for (const uint64_t &i : inVec) {
    ++frequencyMap[i];
  }

  for (const auto &p : frequencyMap) {
    BenchReport::log(std::to_string(p.first) + " - " +
                     std::to_string(p.second));
  }

  BenchReport::log("Distribution Report Complete");

  return frequencyMap;
}

void BenchStatics::generateDistributionRatio(
    std::unordered_map<uint64_t, int> &frequencyMap,
    const std::string &reportTypeMsg) {

  if (frequencyMap.empty()) {
    BenchReport::log("Invalid Distribution: frequency map is empty");
    return;
  }

  auto [min, max] = std::minmax_element(
      frequencyMap.begin(), frequencyMap.end(),
      [](const auto &a, const auto &b) { return a.second < b.second; });

  if (max->second == 0) {
    BenchReport::log("Invalid Distribution: max has frequency of 0");
    return;
  }

  double ratio = static_cast<double>(min->second) / max->second;

  BenchReport::log("Distribution Ratio for " + reportTypeMsg + ": " +
                   std::to_string(ratio) + " (the closer to 1 the better)\n");
}
