#include "pch.h"
#include "r2_FrameBuffer.h"

#include <cassert>
#include <iostream>

namespace r2
{
	FrameBuffer::FrameBuffer( const std::size_t width, const std::size_t height ) :
		mGridIndexConverter( width, height )
		, mChars( width * height, '@' )
	{
		assert( 0u < width && 0u < height );
	}

	void FrameBuffer::Draw() const
	{
		for( std::size_t y = 0u; mGridIndexConverter.GetHeight() > y; ++y )
		{
			for( std::size_t x = 0u; mGridIndexConverter.GetWidth() > x; ++x )
			{
				std::cout << mChars[ ( y * mGridIndexConverter.GetHeight() ) + x ];
			}

			std::cout << r2::linefeed;
		}
	}
}