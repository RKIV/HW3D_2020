#include "IvyTimer.h"

using namespace std::chrono;

IvyTimer::IvyTimer() noexcept
{
	last = steady_clock::now();
}

float IvyTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float IvyTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}