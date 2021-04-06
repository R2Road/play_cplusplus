#pragma once

#include "r2_iScene.h"

namespace r2
{
	class RootScene : public iScene
	{
	private:
		using MyT = RootScene;

	public:
		RootScene( Director& director, const char* title_string );

		static SceneUp Create( Director& director );
	};
}