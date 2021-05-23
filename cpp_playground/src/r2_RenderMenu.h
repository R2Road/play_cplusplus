#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class RenderMenu
	{
	private:
		RenderMenu() = delete;

	public:
		static const char* GetTitle() { return "Render"; }
		static MenuUp Create( Director& director );
	};
}