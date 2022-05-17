#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;
	class Director;
}

class VariadicTemplateMenu
{
private:
	VariadicTemplateMenu() = delete;

public:
	static const char* GetTitle() { return "Variadic Template"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};