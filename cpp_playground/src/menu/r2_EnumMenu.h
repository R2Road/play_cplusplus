#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class EnumMenu
	{
	private:
		EnumMenu() = delete;

	public:
		static const char* GetTitle() { return "Enum"; }
		static MenuUp Create( Director& director );
	};
}