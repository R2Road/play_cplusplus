#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class TemplateScene
	{
	private:
		TemplateScene() = delete;

	public:
		static const char* GetTitle() { return "Template"; }
		static MenuUp Create( Director& director );
	};
}