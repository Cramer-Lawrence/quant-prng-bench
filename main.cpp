#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

#include "BenchReport.h"
#include "BenchStatics.h"
#include "libprng/include/lcg.hpp"
#include "libseed/include/SeedGenerator.h"
#include "timer.h"

std::vector<uint64_t> generateLCGRandoms_Implicit(const int &n, const int &max);
std::vector<uint64_t> generateLCGRandoms_Entropy(const int &n, const int &max);
std::vector<uint64_t> generateLCGRandoms_Hashed(const int &n, const int &max);

template <typename T> void printVector(std::vector<T> vec) {
  for (T &t : vec) {
    std::cout << t << "\n";
  }

  std::cout << std::endl;
}

int main(int argc, char *argv[]) {

  const int n{std::stoi(argv[1])};
  const int m{std::stoi(argv[2])};

  BenchStatics::calculateDistribution(generateLCGRandoms_Implicit(n, m), "LCG Implicit");
  BenchStatics::calculateDistribution(generateLCGRandoms_Entropy(n, m), "LCG Entroy");
  BenchStatics::calculateDistribution(generateLCGRandoms_Hashed(n, m), "LCG Hashed");

  BenchReport::endLog();

  return 0;
}

std::vector<uint64_t> generateLCGRandoms_Implicit(const int &n, const int &max) {
  libbench::Timer t{"LCG Implicit Seed"};

  std::vector<uint64_t> outVec{};

  SeedGenerator sg{};
  libprng::LCG lcg{sg.generateImplicitSeed()};
  BenchReport::log("Generating " + std::to_string(n) +
                   " LCG PRNG numbers with Implicit Seed...");

  for (int i{}; i < n; ++i) {
    outVec.push_back(lcg.next(max));
  }
  return outVec;
}

std::vector<uint64_t> generateLCGRandoms_Entropy(const int &n, const int &max) {
  libbench::Timer t{"LCG Entropy Seed"};

  std::vector<uint64_t> outVec{};

  SeedGenerator sg{};
  libprng::LCG lcg{sg.generateEntropySeed()};
  BenchReport::log("Generating " + std::to_string(n) +
                   " LCG PRNG numbers with Entropy Seed...");

  for (int i{}; i < n; ++i) {
    outVec.push_back(lcg.next(max));
  }

  return outVec;
}

std::vector<uint64_t> generateLCGRandoms_Hashed(const int &n, const int &max) {
  libbench::Timer t{"LCG Hashed Seed"};

  std::vector<uint64_t> outVec{};

  SeedGenerator sg{};
  libprng::LCG lcg{sg.generateHashedSeed()};
  BenchReport::log("Generating " + std::to_string(n) +
                   " LCG PRNG numbers with Hashed Seed...");

  for (int i{}; i < n; ++i) {
    outVec.push_back(lcg.next(max));
  }

  return outVec;
}
