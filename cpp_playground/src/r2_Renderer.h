#pragma once

#include <list>

#include "r2_Renderable.h"

namespace r2
{
	class Renderer
	{
	public:
		using ContainerT = std::list<Renderable*>;

		Renderer();

		void Add( Renderable* const renderable );

		void Draw();

	private:
		ContainerT mContainer;
	};
}