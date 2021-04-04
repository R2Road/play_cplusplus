#pragma once

#include "r2_iScene.h"

namespace r2
{
	class Scene : public iScene
	{
	private:
		using MyT = Scene;

	public:
		Scene( Director& director );
		static SceneUp Create( Director& director );

		void ShowMenu() override;
		eResult Do( const int key_code ) override;
	};
}