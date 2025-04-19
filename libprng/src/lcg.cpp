#include "lcg.hpp"

#include <iostream>

namespace libprng {
LCG::LCG(uint64_t seed) : state_(seed) {}

uint64_t LCG::next() {

  const uint64_t m { 15 };
  const uint64_t a { 8 };
  const uint64_t c { 3 };

  state_ = (state_ * a + c) % m;
  
  return state_;
}
} // namespace libprng
