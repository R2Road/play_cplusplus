#pragma once

#include <list>

#include "r2_Renderable.h"

namespace r2
{
	class Camera;

	class Renderer
	{
	public:
		using ContainerT = std::list<Renderable*>;

		Renderer();

		void SetCamera( r2::Camera* const camera )
		{
			mCamera = camera;
		}

		void Add( Renderable* const renderable );

		void Draw();

	private:
		r2::Camera* mCamera;
		ContainerT mContainer;
	};
}