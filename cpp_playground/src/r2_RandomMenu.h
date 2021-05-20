#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class RandomMenu
	{
	private:
		RandomMenu() = delete;

	public:
		static const char* GetTitle() { return "Random"; }
		static MenuUp Create( Director& director );
	};
}