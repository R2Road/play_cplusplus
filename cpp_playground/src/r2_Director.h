#pragma once

#include "r2_iScene.h"

namespace r2
{
	class Director
	{
	public:
		Director();

		void Setup( SceneUp scene );

		void Update();

	private:
		SceneUp mScene;
	};
}