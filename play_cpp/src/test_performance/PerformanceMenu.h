#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class PerformanceMenu
{
private:
	PerformanceMenu() = delete;

public:
	static const char* GetTitle() { return "Performance Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};