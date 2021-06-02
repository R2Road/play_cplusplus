#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class RootMenu
	{
	private:
		RootMenu() = delete;

	public:
		static const char* GetTitle() { return "Root"; }
		static MenuUp Create( Director& director );
	};
}