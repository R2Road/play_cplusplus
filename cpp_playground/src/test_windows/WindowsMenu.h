#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class WindowsMenu
{
private:
	WindowsMenu() = delete;

public:
	static const char* GetTitle() { return "Windows Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};