#include "libprng/lcg.hpp"

namespace libprng {
	LCG::LCG(uint64_t seed) : state_(seed) {}

	uint64_t LCG::next() {
		state_ = 6364136223846793005ULL * state_ + 1;
		return state_;
	}
}
