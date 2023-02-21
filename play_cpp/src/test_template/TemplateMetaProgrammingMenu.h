#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class TemplateMetaProgrammingMenu
{
private:
	TemplateMetaProgrammingMenu() = delete;

public:
	static const char* GetTitle() { return "Template Meta Programming Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};