#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class STDMemoryMenu
{
private:
	STDMemoryMenu() = delete;

public:
	static const char* GetTitle() { return "std::memory Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};