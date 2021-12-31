#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class PerformanceMenu
	{
	private:
		PerformanceMenu() = delete;

	public:
		static const char* GetTitle() { return "Performance"; }
		static MenuUp Create( Director& director );
	};
}