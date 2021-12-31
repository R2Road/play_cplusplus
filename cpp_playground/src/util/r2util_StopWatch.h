#pragma once

#include <chrono>

namespace r2util
{
	class StopWatch
	{
	public:
		StopWatch();

		void Start();
		void Stop();

		long long GetTime() const;
		long long GetMaxTime() const { return mMaxTime; }
		long long GetMinTime() const { return mMinTime; }

		void PrintLog();

	private:
		std::chrono::steady_clock::time_point mStartTime;
		std::chrono::steady_clock::time_point mEndTime;

		long long mMaxTime;
		long long mMinTime;
	};
}
