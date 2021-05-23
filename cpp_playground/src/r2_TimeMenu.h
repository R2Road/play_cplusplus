#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class TimeMenu
	{
	private:
		TimeMenu() = delete;

	public:
		static const char* GetTitle() { return "Time"; }
		static MenuUp Create( Director& director );
	};
}