#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class ArrayBasedListMenu
{
private:
	ArrayBasedListMenu() = delete;

public:
	static const char* GetTitle() { return "Array Based List Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};