#pragma once

#include <vector>

namespace r2_game
{
	class FrameBuffer
	{
	public:
		FrameBuffer( const std::size_t width, const std::size_t height );

	public:
		void Draw() const;

	private:
		const std::size_t mWidth;
		const std::size_t mHeight;
		std::vector<char> mChars;
	};
}