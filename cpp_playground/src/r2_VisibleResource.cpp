#include "pch.h"
#include "r2_VisibleResource.h"

#include <algorithm>
#include <cassert>

namespace r2
{
	VisibleResource::VisibleResource( const std::string_view str ) :
		mGridIndexConverter( str.length(), 1u )
		, mChars( mGridIndexConverter.GetWidth() * mGridIndexConverter.GetHeight(), 32 )
		, mVisibleRect( 0, 0, mGridIndexConverter.GetWidth(), mGridIndexConverter.GetHeight() )
	{
		assert( 0u < mGridIndexConverter.GetWidth() && 0u < mGridIndexConverter.GetHeight() );

		//std::copy( str.begin(), str.end(), mChars.begin() );

		memcpy( &mChars[0], str.data(), mChars.size() );
	}
	VisibleResource::VisibleResource( const std::size_t width, const std::string_view str ) :
		mGridIndexConverter( width, ( str.length() < 0 ? 1 : ( str.length() / width ) + ( str.length() % width < 1 ? 0 : 1 ) ) )
		, mChars( mGridIndexConverter.GetWidth() * mGridIndexConverter.GetHeight(), 32 )
		, mVisibleRect( 0, 0, mGridIndexConverter.GetWidth(), mGridIndexConverter.GetHeight() )
	{
		assert( 0u < mGridIndexConverter.GetWidth() && 0u < mGridIndexConverter.GetHeight() );

		memcpy( &mChars[0], str.data(), mChars.size() );
	}
	VisibleResource::VisibleResource( const std::size_t width, const std::size_t height ) :
		mGridIndexConverter( width, height )
		, mChars( width * height, 32 )
		, mVisibleRect( 0, 0, mGridIndexConverter.GetWidth(), mGridIndexConverter.GetHeight() )
	{
		assert( 0u < width && 0u < height );
	}

	VisibleResource::ValueT VisibleResource::Get( std::size_t x, std::size_t y ) const
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		return mChars[target_linear_index];
	}

	void VisibleResource::FillAll( const char c )
	{
		for( char& element : mChars )
		{
			element = c;
		}
	}

	void VisibleResource::Fill( std::size_t x, std::size_t y, const char c )
	{
		const auto target_linear_index = mGridIndexConverter.To_Linear( x, y );

		mChars[target_linear_index] = c;
	}
}