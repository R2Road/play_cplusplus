#pragma once

#include <string_view>
#include <vector>

#include "r2_GridIndexConverter.h"

namespace r2
{
	class FrameBuffer
	{
	public:
		FrameBuffer( const std::size_t width, const std::size_t height );

	public:
		int GetWidth() const { return mGridIndexConverter.GetWidth(); }
		int GetHeight() const { return mGridIndexConverter.GetHeight(); }

		void Fill( std::size_t x, std::size_t y, const char c );
		void Draw() const;

	private:
		const GridIndexConverter mGridIndexConverter;
		std::vector<char> mChars;
	};
}