/*######################################################
#
# + Summary
#   > Cache 크기 만큼의 메모리에 강제 접근.
#   > L1, L2, L3 캐쉬를 무의미한 데이터로 채운다.
#
######################################################*/

#pragma once

namespace r2tm
{
	class CacheCleaner
	{
	public:
		using BufferT = unsigned long long;

		CacheCleaner( const int buffer_scale = 1 );
		CacheCleaner( const CacheCleaner& c );
		~CacheCleaner();

		//
		//
		//
		CacheCleaner& operator=( const CacheCleaner& ) = delete;

		//
		//
		//
		int GetBufferScale() const
		{
			return mBufferScale;
		}
		int GetCacheByteSize() const
		{
			return mCacheByteSize;
		}
		int GetBufferSize() const
		{
			return mBufferSize;
		}

		//
		//
		//
		void Clean();

	private:
		const int mBufferScale;
		int mCacheByteSize;
		int mBufferSize;
		BufferT* mBuffer;
	};
}
