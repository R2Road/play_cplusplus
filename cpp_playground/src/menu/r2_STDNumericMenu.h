#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class STDNumericMenu
	{
	private:
		STDNumericMenu() = delete;

	public:
		static const char* GetTitle() { return "Numeric"; }
		static MenuUp Create( Director& director );
	};
}