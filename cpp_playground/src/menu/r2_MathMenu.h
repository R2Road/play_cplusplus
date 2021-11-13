#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class MathMenu
	{
	private:
		MathMenu() = delete;

	public:
		static const char* GetTitle() { return "Math"; }
		static MenuUp Create( Director& director );
	};
}