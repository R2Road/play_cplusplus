#pragma once

#include "r2_Scene.h"

namespace r2
{
	class RootScene : public Scene
	{
	private:
		using MyT = RootScene;

	public:
		RootScene( Director& director, const char* title_string );

		static SceneUp Create( Director& director );
	};
}