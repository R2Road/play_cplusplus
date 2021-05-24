#pragma once

#include <chrono>

namespace r2
{
	class FrameManager
	{
	public:
		FrameManager();

		void SetFPS( const std::size_t frame_count );

		void Reset();
		bool Update();

	private:
		long long mFPS;
		std::chrono::time_point<std::chrono::system_clock> mPivotTimePoint;
		std::chrono::milliseconds mCurrentTime;
		std::chrono::milliseconds mLastTime;
	};
}