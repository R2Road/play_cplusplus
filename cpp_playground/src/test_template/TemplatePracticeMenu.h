#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class TemplatePracticeMenu
{
private:
	TemplatePracticeMenu() = delete;

public:
	static const char* GetTitle() { return "Template Practice"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};