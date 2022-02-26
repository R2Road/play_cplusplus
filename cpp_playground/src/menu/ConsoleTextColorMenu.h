#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class ConsoleTextColorMenu
{
private:
	ConsoleTextColorMenu() = delete;

public:
	static const char* GetTitle() { return "Console Text Color"; }
	static r2::MenuUp Create( r2::Director& director );
};