#pragma once

#include "r2_Scene.h"

namespace r2
{
	class RandomTestScene : public Scene
	{
	private:
		using MyT = RandomTestScene;

	public:
		RandomTestScene( Director& director, const char* title_string );

		static SceneUp Create( Director& director );
	};
}