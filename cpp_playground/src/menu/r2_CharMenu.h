#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class CharMenu
	{
	private:
		CharMenu() = delete;

	public:
		static const char* GetTitle() { return "Char"; }
		static MenuUp Create( Director& director );
	};
}