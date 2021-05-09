#pragma once

#include <string_view>
#include <vector>

#include "r2_GridIndexConverter.h"

namespace r2
{
	class FrameBuffer
	{
	public:
		using ContainerT = std::vector<char>;
		using ConstIteratorT = typename ContainerT::const_iterator;

		FrameBuffer( const std::string_view str );
		FrameBuffer( const std::size_t width, const std::string_view str );
		FrameBuffer( const std::size_t width, const std::size_t height );

	public:
		//
		// Iteration
		//
		ConstIteratorT begin() const { return mChars.begin(); }
		ConstIteratorT end() const { return mChars.end(); }

		//
		// Getter
		//
		int GetWidth() const { return mGridIndexConverter.GetWidth(); }
		int GetHeight() const { return mGridIndexConverter.GetHeight(); }
		const ContainerT GetContainer() const { return mChars; }

		//
		//
		//
		void FillAll( const char c );
		void Fill( std::size_t x, std::size_t y, const char c );

	private:
		const GridIndexConverter mGridIndexConverter;
		ContainerT mChars;
	};
}