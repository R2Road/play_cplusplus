#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class STDCoutMenu
{
private:
	STDCoutMenu() = delete;

public:
	static const char* GetTitle() { return "std::cout Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};