#pragma once

#include "r2_FrameBuffer.h"
#include "r2_Renderable.h"

namespace r2
{
	class Renderer
	{
	public:
		Renderer();

		void Add( Renderable* const renderable );

		void Draw();

	private:
		Renderable* mRenderable;
	};
}