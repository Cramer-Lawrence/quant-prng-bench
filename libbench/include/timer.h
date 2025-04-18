#ifndef TIMER_H
#define TIMER_H

#include <string>
#include <chrono>

namespace libbench
{

class Timer
{
private:
	using Clock = std::chrono::high_resolution_clock;
	std::chrono::time_point<Clock> m_startTime { Clock::now() };
	std::string m_name {};

public:
	Timer(const std::string name)
	: m_name { name } {};

	~Timer();
};
}
#endif
