#pragma once

#include "r2_iScene.h"

namespace r2
{
	class RandomTestScene : public iScene
	{
	private:
		using MyT = RandomTestScene;

	public:
		RandomTestScene( Director& director );
		static SceneUp Create( Director& director );

		void ShowMenu() override;
		eResult Do( const int key_code ) override;
	};
}