#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class STDStringViewMenu
{
private:
	STDStringViewMenu() = delete;

public:
	static const char* GetTitle() { return "<string_view>"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};