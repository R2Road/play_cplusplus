#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class MemoryPoolMenu
{
private:
	MemoryPoolMenu() = delete;

public:
	static const char* GetTitle() { return "Memory Pool( Inprogress )"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};