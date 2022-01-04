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

		long long GetMilliTime() const;
		long long GetMicroTime() const;
		long long GetNanoTime() const;
		long long GetMaxTime() const { return mMaxTime; }
		long long GetMinTime() const { return mMinTime; }

		void PrintLog_MilliSeconds();
		void PrintLog_MicroSeconds();
		void PrintLog_NanoSeconds();
		void PrintLog_All();

	private:
		std::chrono::steady_clock::time_point mStartTime;
		std::chrono::steady_clock::time_point mEndTime;

		long long mMaxTime;
		long long mMinTime;
	};
}
