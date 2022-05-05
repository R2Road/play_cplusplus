#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

namespace r2
{
	class MathMenu
	{
	private:
		MathMenu() = delete;

	public:
		static const char* GetTitle() { return "Math"; }
		static r2cm::MenuUp Create( r2cm::Director& director );
	};
}