#pragma once

#include "r2_Menu.h"

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