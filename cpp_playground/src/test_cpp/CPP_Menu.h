#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class C_CPP_Menu
{
private:
	C_CPP_Menu() = delete;

public:
	static const char* GetTitle() { return "C, CPP Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};