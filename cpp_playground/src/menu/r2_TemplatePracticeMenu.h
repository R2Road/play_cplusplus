#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class TemplatePracticeMenu
	{
	private:
		TemplatePracticeMenu() = delete;

	public:
		static const char* GetTitle() { return "Template Practice"; }
		static MenuUp Create( Director& director );
	};
}