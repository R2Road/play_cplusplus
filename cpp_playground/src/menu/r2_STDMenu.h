#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class STDMenu
	{
	private:
		STDMenu() = delete;

	public:
		static const char* GetTitle() { return "STD"; }
		static MenuUp Create( Director& director );
	};
}