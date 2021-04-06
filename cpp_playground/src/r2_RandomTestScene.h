#pragma once

#include "r2_iScene.h"

namespace r2
{
	class RandomTestScene : public iScene
	{
	private:
		using MyT = RandomTestScene;

	public:
		RandomTestScene( Director& director, const char* title_string );

		static SceneUp Create( Director& director );
	};
}