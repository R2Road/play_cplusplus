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
		std::size_t x = 0;
		for( const char element : mChars )
		{
			std::cout << element;

			++x;
			if( mGridIndexConverter.GetWidth() <= x )
			{
				x = 0u;
				std::cout << r2::linefeed;
			}
		}
	}
}