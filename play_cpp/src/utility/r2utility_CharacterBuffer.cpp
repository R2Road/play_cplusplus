#include "r2utility_CharacterBuffer.h"

#include <cassert>

namespace play_cpp_utility
{
	CharacterBuffer::CharacterBuffer( const uint32_t width, const uint32_t height ) :
		mGridIndexConverter( static_cast<int>( width ), static_cast<int>( height ) )
		, mChars(
			( width * height )		// for buffer
			+ 1u					// for \0
			, 32					// Fill : Character : Space
		)
	{
		assert( 0u < width && 0u < height && "CharacterBuffer::CharacterBuffer" );

		//
		// End
		//
		*mChars.rbegin() = '\0';
	}

	std::string_view CharacterBuffer::GetLine( const uint32_t y ) const
	{
		std::string_view temp( &mChars[0] );
		return temp.substr( mGridIndexConverter.To_Linear( 0, y ), mGridIndexConverter.GetWidth() );
	}

	void CharacterBuffer::FillAll( const char c )
	{
		//
		// Fill
		//
		std::fill( mChars.begin(), mChars.end(), c );

		//
		// End
		//
		*mChars.rbegin() = '\0';
	}
}