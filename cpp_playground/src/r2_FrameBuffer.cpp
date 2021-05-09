#include "pch.h"
#include "r2_FrameBuffer.h"

#include <algorithm>
#include <cassert>
#include <iostream>

namespace r2
{
	FrameBuffer::FrameBuffer( const std::string_view str ) :
		mGridIndexConverter( str.length(), 1u )
		, mChars( str.length(), 32 )
	{
		assert( 0u < mGridIndexConverter.GetWidth() && 0u < mGridIndexConverter.GetHeight() );

		//std::copy( str.begin(), str.end(), mChars.begin() );

		memcpy( &mChars[0], str.data(), mChars.size() );
	}
	FrameBuffer::FrameBuffer( const std::size_t width, const std::string_view str ) :
		mGridIndexConverter( width, ( str.length() < 0 ? 1 : ( str.length() / width ) + ( str.length() % width < 1 ? 0 : 1 ) ) )
		, mChars( str.length(), 32 )
	{
		assert( 0u < mGridIndexConverter.GetWidth() && 0u < mGridIndexConverter.GetHeight() );

		memcpy( &mChars[0], str.data(), mChars.size() );
	}
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
}