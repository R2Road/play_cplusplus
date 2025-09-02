#pragma once

#include "r2tm_menu_processor.hpp"

namespace r2tm
{
	class iMenu;

	class Director
	{
	public:
		Director();

		void Setup( const iMenu& menu );

		void Run();

	private:
		MenuProcessor mMenuProcessor;
	};
}