#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class TestWindowsMenu
{
private:
	TestWindowsMenu() = delete;

public:
	static const char* GetTitle() { return "Test Windows"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};