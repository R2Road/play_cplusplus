#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class ETCMenu
{
private:
	ETCMenu() = delete;

public:
	static const char* GetTitle() { return "ETC"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};