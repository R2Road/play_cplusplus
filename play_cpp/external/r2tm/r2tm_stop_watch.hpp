#pragma once

#include <chrono>

namespace r2tm
{
	class StopWatch
	{
	public:
		StopWatch();

		void Reset();
		void Start();
		void Stop();

		long long GetMilliTime() const;
		long long GetMicroTime() const;
		long long GetNanoTime() const;
		long long GetMaxTime() const { return mMaxTime; }
		long long GetMinTime() const { return mMinTime; }

		long long GetAccumulateTime() const { return mAccumulateTime; }
		long long GetAccumulateCount() const { return mAccumulateCount; }
		long long GetAverageTime() const { return ( mAccumulateTime / std::max( 1ll, mAccumulateCount ) ); }

		void PrintElapsedTime_MilliSeconds();
		void PrintElapsedTime_MicroSeconds();
		void PrintElapsedTime_NanoSeconds();
		void PrintElapsedTime_All();

		void PrintMinAndMaxTime_MilliSeconds();
		void PrintMinAndMaxTime_MicroSeconds();
		void PrintMinAndMaxTime_NanoSeconds();

		void PrintAverageTime_MilliSeconds();
		void PrintAverageTime_MicroSeconds();
		void PrintAverageTime_NanoSeconds();
		void PrintAverageTime_All();

	private:
		std::chrono::steady_clock::time_point mStartTime;
		std::chrono::steady_clock::time_point mEndTime;

		long long mMaxTime;
		long long mMinTime;

		long long mAccumulateTime;
		long long mAccumulateCount;
	};
}
