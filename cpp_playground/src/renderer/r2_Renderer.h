#pragma once

#include <list>

namespace r2
{
	class Camera;
	class iRenderable;

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