#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class C_CPP_Menu
{
private:
	C_CPP_Menu() = delete;

public:
	static const char* GetTitle() { return "C, CPP Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};