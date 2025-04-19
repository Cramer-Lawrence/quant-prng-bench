#ifndef LCG_HPP
#define LCG_HPP

#include <cstdint>

namespace libprng {

class LCG {
private:
  uint64_t m_seed;

public:
  LCG(uint64_t seed) : m_seed{seed} {};

  uint64_t next(const int &maxValue = 100);
};

} // namespace libprng

#endif
