#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;
	class Director;
}

class ClassMenu
{
private:
	ClassMenu() = delete;

public:
	static const char* GetTitle() { return "Class"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};