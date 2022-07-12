#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class MathMenu
{
private:
	MathMenu() = delete;

public:
	static const char* GetTitle() { return "Math"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};