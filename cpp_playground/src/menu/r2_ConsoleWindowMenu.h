#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class ConsoleWindowMenu
	{
	private:
		ConsoleWindowMenu() = delete;

	public:
		static const char* GetTitle() { return "Console Window"; }
		static MenuUp Create( Director& director );
	};
}