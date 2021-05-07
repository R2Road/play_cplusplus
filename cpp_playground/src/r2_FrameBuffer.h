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
		void Draw() const;

	private:
		const GridIndexConverter mGridIndexConverter;
		std::vector<char> mChars;
	};
}