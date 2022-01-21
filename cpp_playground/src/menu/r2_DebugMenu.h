#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class DebugMenu
	{
	private:
		DebugMenu() = delete;

	public:
		static const char* GetTitle() { return "Debug"; }
		static MenuUp Create( Director& director );
	};
}