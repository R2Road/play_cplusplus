#pragma once

#include "r2_iScene.h"

namespace r2
{
	class Scene : public iScene
	{
	private:
		using MyT = Scene;

	public:
		Scene( Director* const director );
		static SceneUp Create( Director* const director );

		void ShowMenu() override;
		bool Do( const int key_code ) override;
	};
}