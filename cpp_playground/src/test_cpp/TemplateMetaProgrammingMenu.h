#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;
	class Director;
}

class TemplateMetaProgrammingMenu
{
private:
	TemplateMetaProgrammingMenu() = delete;

public:
	static const char* GetTitle() { return "Template Meta Programming"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};