#ifndef LCG_HPP
#define LCG_HPP

#include <cstdint>

namespace libprng {
class LCG {
public:
	LCG() = default;
	LCG(uint64_t seed);
	uint64_t next();
private:
	uint64_t state_;
};

}

#endif
