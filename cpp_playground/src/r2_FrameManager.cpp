#include "pch.h"
#include "r2_FrameManager.h"

namespace r2
{
	FrameManager::FrameManager() :
		mPivotTimePoint()
		, mCurrentTime()
		, mLastTime()
	{}

	void FrameManager::Reset()
	{
		mPivotTimePoint = std::chrono::system_clock::now();
		mCurrentTime = std::chrono::duration_cast<std::chrono::milliseconds>( mPivotTimePoint - mPivotTimePoint );
		mLastTime = mCurrentTime;
	}
	bool FrameManager::Update()
	{
		mCurrentTime = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::system_clock::now() - mPivotTimePoint );
		if( 32 > mCurrentTime.count() - mLastTime.count() )
		{
			return false;
		}

		mLastTime = mCurrentTime;

		return true;
	}
}