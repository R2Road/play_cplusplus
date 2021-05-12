#pragma once

#include <list>

#include "r2_iRenderable.h"

namespace r2
{
	class Camera;

	class Renderer
	{
	public:
		using ContainerT = std::list<iRenderable*>;

		Renderer();

		void SetCamera( r2::Camera* const camera )
		{
			mCamera = camera;
		}

		void Clear();
		void Add( iRenderable* const renderable );

		void Draw();

	private:
		r2::Camera* mCamera;
		ContainerT mContainer;
	};
}