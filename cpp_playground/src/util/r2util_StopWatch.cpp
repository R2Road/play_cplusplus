#include "r2util_StopWatch.h"

#include <iostream>
#include <numeric>

namespace r2util
{
	StopWatch::StopWatch() :
		mStartTime( std::chrono::nanoseconds::duration( 0 ) )
		, mEndTime( std::chrono::nanoseconds::duration( 0 ) )

		, mMaxTime( 0ll )
		, mMinTime( std::numeric_limits<long long>::max() )
	{}

	void StopWatch::Start()
	{
		mEndTime = mStartTime = std::chrono::high_resolution_clock::now();
	}
	void StopWatch::Stop()
	{
		mEndTime = std::chrono::high_resolution_clock::now();

		const auto current_time = std::chrono::duration_cast<std::chrono::microseconds>( mEndTime - mStartTime ).count();
		if( current_time > mMaxTime )
		{
			mMaxTime = current_time;
		}
		if( current_time < mMinTime )
		{
			mMinTime = current_time;
		}
	}

	long long StopWatch::GetMilliTime() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>( mEndTime - mStartTime ).count();
	}
	long long StopWatch::GetMicroTime() const
	{
		return std::chrono::duration_cast<std::chrono::microseconds>( mEndTime - mStartTime ).count();
	}
	long long StopWatch::GetNanoTime() const
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>( mEndTime - mStartTime ).count();
	}

	void StopWatch::PrintLog_MilliSeconds()
	{
		std::cout << GetMilliTime() << "ms";
	}
	void StopWatch::PrintLog_MicroSeconds()
	{
		std::cout << GetMicroTime() << "¥ìs";
	}
	void StopWatch::PrintLog_NanoSeconds()
	{
		std::cout << GetNanoTime() << "ns";
	}
}