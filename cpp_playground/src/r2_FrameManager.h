#pragma once

#include <chrono>

namespace r2
{
	class FrameManager
	{
	public:
		FrameManager();

		void Reset();
		bool Update();

	private:
		std::chrono::time_point<std::chrono::system_clock> mPivotTimePoint;
		std::chrono::milliseconds mCurrentTime;
		std::chrono::milliseconds mLastTime;
	};
}