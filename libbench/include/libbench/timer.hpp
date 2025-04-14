#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

namespace libbench {

class Timer {
public:
	Timer();
	void reset();
	double elapsed() const;

private:
	std::chrono::high_resolution_clock::time_point start_;
};

}

#endif
