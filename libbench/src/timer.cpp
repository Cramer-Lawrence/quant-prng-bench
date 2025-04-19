#include "timer.h"
#include "BenchReport.h"

#include <iostream>

namespace libbench {

Timer::~Timer()
{
	std::chrono::time_point<Clock> endTime { Clock::now() };
	const auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTime - m_startTime).count();

	std::string reportString { m_name + " took " };

	if (microseconds < 1000)
	{
		reportString +=  (std::to_string(microseconds) + "µs to execute.");
	}
	else
	{
		reportString += (std::to_string(microseconds / 1000) + "ms to execute");
	}
	BenchReport::log(reportString);
}

} // namespace libbench
