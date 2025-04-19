#include "lcg.hpp"

#include <iostream>

namespace libprng {

uint64_t LCG::next(const int &maxValue) {

  const uint64_t m{ static_cast<uint64_t>(2e64) };
  const uint64_t a{ 500 };
  const uint64_t c{ m_seed + 1 };

  m_seed = ((m_seed * a) + c) % m;

  return (m_seed % (maxValue + 1)); // use the remainder to bracket in the max value for the random set
}

} // namespace libprng
