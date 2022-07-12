#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class BitOperationMenu
{
private:
	BitOperationMenu() = delete;

public:
	static const char* GetTitle() { return "Bit Operation Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};