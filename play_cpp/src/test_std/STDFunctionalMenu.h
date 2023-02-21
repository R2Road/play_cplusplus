#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class STDFunctionalMenu
{
private:
	STDFunctionalMenu() = delete;

public:
	static const char* GetTitle() { return "<functional>"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};