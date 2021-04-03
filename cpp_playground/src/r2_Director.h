#pragma once

#include "r2_iScene.h"

namespace r2
{
	class Director
	{
	public:
		Director();

		template<typename T>
		void Setup()
		{
			mScene.reset( new ( std::nothrow ) T );
		}

		bool Update();

	private:
		SceneUp mScene;
	};
}