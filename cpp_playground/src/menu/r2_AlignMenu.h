#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class AlignMenu
	{
	private:
		AlignMenu() = delete;

	public:
		static const char* GetTitle() { return "Align"; }
		static MenuUp Create( Director& director );
	};
}