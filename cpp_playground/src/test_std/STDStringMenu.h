#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class STDStringMenu
{
private:
	STDStringMenu() = delete;

public:
	static const char* GetTitle() { return "std::string Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};