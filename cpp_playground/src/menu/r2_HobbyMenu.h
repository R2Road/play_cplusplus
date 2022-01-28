#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class HobbyMenu
	{
	private:
		HobbyMenu() = delete;

	public:
		static const char* GetTitle() { return "Hobby"; }
		static MenuUp Create( Director& director );
	};
}