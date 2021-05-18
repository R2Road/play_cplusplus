#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class TemplatePracticeScene
	{
	private:
		TemplatePracticeScene() = delete;

	public:
		static const char* GetTitle() { return "Template Practice"; }
		static MenuUp Create( Director& director );
	};
}