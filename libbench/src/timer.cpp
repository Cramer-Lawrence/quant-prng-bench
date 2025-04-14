#include "libbench/timer.hpp"

namespace libbench {

Timer::Timer() { reset(); }

void Timer::reset() { start_ = std::chrono::high_resolution_clock::now(); }

double Timer::elapsed() const {
  auto now = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = now - start_;
  return diff.count();
}
} // namespace libbench
