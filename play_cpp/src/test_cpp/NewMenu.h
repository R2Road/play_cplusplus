#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class NewMenu
{
private:
	NewMenu() = delete;

public:
	static const char* GetTitle() { return "New Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};