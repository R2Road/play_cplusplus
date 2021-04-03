#pragma once

#include "r2_iScene.h"

namespace r2
{
	class Scene : public iScene
	{
	private:
		using MyT = Scene;

	public:
		static SceneUp Create();

		void ShowMenu() override;
		int Do( const int key_code ) override;
	};
}