#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class NewMenu
	{
	private:
		NewMenu() = delete;

	public:
		static const char* GetTitle() { return "New"; }
		static MenuUp Create( Director& director );
	};
}