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

		int Do() override;
	};
}