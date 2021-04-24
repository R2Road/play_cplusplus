#include "pch.h"
#include "r2_game_FrameBuffer.h"

#include <iostream>

namespace r2_game
{
	FrameBuffer::FrameBuffer( const std::size_t width, const std::size_t height ) :
		mWidth( width )
		, mHeight( height )
		, mChars( width * height, '@' )
	{}

	void FrameBuffer::Flip() const
	{
		for( std::size_t y = 0u; mHeight > y; ++y )
		{
			for( std::size_t x = 0u; mWidth > x; ++x )
			{
				std::cout << mChars[ ( y * mHeight ) + x ];
			}

			std::cout << r2::linefeed;
		}
	}
}