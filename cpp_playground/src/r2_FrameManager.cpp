#include "pch.h"
#include "r2_FrameManager.h"

#include <cassert>

namespace r2
{
	FrameManager::FrameManager() :
		mFPS( 0ll )
		, mPivotTimePoint()
		, mCurrentTime()
		, mLastTime()
	{}

	void FrameManager::SetFPS( const std::size_t frame_count )
	{
		assert( 0 < frame_count );

		mFPS = 1000 / frame_count;
	}

	void FrameManager::Reset()
	{
		mPivotTimePoint = std::chrono::system_clock::now();
		mCurrentTime = std::chrono::duration_cast<std::chrono::milliseconds>( mPivotTimePoint - mPivotTimePoint );
		mLastTime = mCurrentTime;
	}
	bool FrameManager::Update()
	{
		mCurrentTime = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::system_clock::now() - mPivotTimePoint );
		if( mFPS > mCurrentTime.count() - mLastTime.count() )
		{
			return false;
		}

		mLastTime = mCurrentTime;

		return true;
	}
}