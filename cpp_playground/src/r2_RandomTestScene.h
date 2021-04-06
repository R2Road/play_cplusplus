#pragma once

#include "r2_Scene.h"

namespace r2
{
	class RandomTestScene
	{
	private:
		RandomTestScene() = delete;

	public:
		static SceneUp Create( Director& director );
	};
}