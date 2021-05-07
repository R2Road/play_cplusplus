#include "pch.h"
#include "r2_FrameBuffer.h"

#include <cassert>
#include <iostream>

namespace r2
{
	FrameBuffer::FrameBuffer( const std::size_t width, const std::size_t height ) :
		mGridIndexConverter( width, height )
		, mChars( width * height, 32 )
	{
		assert( 0u < width && 0u < height );
	}

	void FrameBuffer::FillAll( const char c )
	{
		for( char& element : mChars )
		{
			element = c;
		}
	}

	void FrameBuffer::Fill( std::size_t x, std::size_t y, const char c )
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mChars[target_linear_index] = c;
	}

	void FrameBuffer::Draw() const
	{
		for( std::size_t y = 0u; mGridIndexConverter.GetHeight() > y; ++y )
		{
			for( std::size_t x = 0u; mGridIndexConverter.GetWidth() > x; ++x )
			{
				std::cout << mChars[ mGridIndexConverter.To_Linear( x, y ) ];
			}

			std::cout << r2::linefeed;
		}
	}
}