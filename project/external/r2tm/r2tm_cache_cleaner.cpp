#include "r2tm_cache_cleaner.hpp"

#include <cstring>

#include "r2tm_windows_utility.hpp"

namespace r2tm
{
	CacheCleaner::CacheCleaner( const int buffer_scale ) : mBufferScale( buffer_scale ), mCacheByteSize( 0 ), mBufferSize(0), mBuffer(nullptr)
	{
		mCacheByteSize = r2tm::WindowsUtility::GetCPUCacheSize();
		mBufferSize = ( mCacheByteSize / sizeof( BufferT ) ) * mBufferScale;

		mBuffer = new BufferT[mBufferSize];
		std::memset( mBuffer, 0, mCacheByteSize );
	}

	CacheCleaner::CacheCleaner( const CacheCleaner& c ) : mBufferScale( c.GetBufferScale() ), mCacheByteSize( c.GetCacheByteSize() ), mBufferSize( c.GetBufferSize() ), mBuffer( nullptr )
	{
		mBuffer = new BufferT[mBufferSize];
		std::memset( mBuffer, 0, mCacheByteSize );
	}

	CacheCleaner::~CacheCleaner()
	{
		delete[] mBuffer;
	}

	void CacheCleaner::Clean()
	{
		for( int i = 0; mBufferSize > i; ++i )
		{
			mBuffer[i] = i;
		}
	}
}