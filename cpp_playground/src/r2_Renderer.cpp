#include "pch.h"
#include "r2_Renderer.h"

#include <stdlib.h>

namespace r2
{
	Renderer::Renderer() : mFrameBuffer( 30, 20 ), mRenderable( nullptr )
	{}

	void Renderer::Add( Renderable* const renderable )
	{
		mRenderable = renderable;
	}

	void Renderer::Draw()
	{
		system( "cls" );

		std::size_t x = 0;
		for( const char element : mFrameBuffer )
		{
			std::cout << element;

			++x;
			if( mFrameBuffer.GetWidth() <= x )
			{
				x = 0u;
				std::cout << r2::linefeed;
			}
		}
	}
}