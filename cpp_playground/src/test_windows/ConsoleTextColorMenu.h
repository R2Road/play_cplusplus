#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class ConsoleTextColorMenu
{
private:
	ConsoleTextColorMenu() = delete;

public:
	static const char* GetTitle() { return "Console Text Color"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};