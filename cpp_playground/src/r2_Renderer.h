#pragma once

#include "r2_FrameBuffer.h"

namespace r2
{
	class Renderer
	{
	public:
		Renderer();

		void Draw();

	private:
		r2::FrameBuffer mFrameBuffer;
	};
}