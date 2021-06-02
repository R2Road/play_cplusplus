#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class VariadicTemplateMenu
	{
	private:
		VariadicTemplateMenu() = delete;

	public:
		static const char* GetTitle() { return "Variadic Template"; }
		static MenuUp Create( Director& director );
	};
}