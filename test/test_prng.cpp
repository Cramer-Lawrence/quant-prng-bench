#include <gtest/gtest.h>	// Google test macros
#include "libprng/lcg.hpp"

TEST(PRNGTest, LCGProducesDifferentNumbers) {
	libprng::LCG rng(42);
	auto first = rng.next();
	auto second = rng.next();
	EXPECT_NE(first, second);
}
