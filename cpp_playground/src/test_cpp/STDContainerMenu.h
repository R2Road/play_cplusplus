#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class STDContainerMenu
{
private:
	STDContainerMenu() = delete;

public:
	static const char* GetTitle() { return "Container"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};