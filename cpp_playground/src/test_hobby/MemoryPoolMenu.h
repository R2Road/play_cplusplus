#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class MemoryPoolMenu
{
private:
	MemoryPoolMenu() = delete;

public:
	static const char* GetTitle() { return "Memory Pool( Researching... )"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};