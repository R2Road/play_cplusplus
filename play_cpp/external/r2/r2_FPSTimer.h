#pragma once

#include <chrono>
#include <stdint.h>

namespace r2
{
	class FPSTimer
	{
	public:
		using FrameCountT = uint32_t;

		FPSTimer( const FrameCountT frame_count = 30u );

		void SetFPS( const FrameCountT frame_count );
		float GetElapsedTime() const { return mElapsedTime; }

		void Reset();
		bool Update();

	private:
		long long mFPS;
		std::chrono::time_point<std::chrono::system_clock> mPivotTimePoint;
		std::chrono::milliseconds mCurrentTime;
		std::chrono::milliseconds mLastTime;

		float mElapsedTime;
	};
}