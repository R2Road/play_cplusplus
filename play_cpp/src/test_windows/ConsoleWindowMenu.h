#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class ConsoleWindowMenu
{
private:
	ConsoleWindowMenu() = delete;

public:
	static const char* GetTitle() { return "Console Window"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};