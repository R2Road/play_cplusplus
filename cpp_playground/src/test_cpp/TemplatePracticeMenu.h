#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;
	class Director;
}

class TemplatePracticeMenu
{
private:
	TemplatePracticeMenu() = delete;

public:
	static const char* GetTitle() { return "Template Practice"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};