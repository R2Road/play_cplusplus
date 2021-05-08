#include "pch.h"
#include "r2_Renderer.h"

#include <stdlib.h>

namespace r2
{
	Renderer::Renderer() : mRenderable( nullptr )
	{}

	void Renderer::Add( Renderable* const renderable )
	{
		mRenderable = renderable;
	}

	void Renderer::Draw()
	{
		system( "cls" );

		if( mRenderable )
		{
			mRenderable->Draw();
		}
	}
}