#pragma once

#include "r2_Scene.h"

namespace r2
{
	class Director
	{
	public:
		Director();

		void Setup( MenuUp menu );

		void Update();

	private:
		MenuUp mMenu;
	};
}