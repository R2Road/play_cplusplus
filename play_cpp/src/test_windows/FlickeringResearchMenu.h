#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class FlickeringResearchMenu
{
private:
	FlickeringResearchMenu() = delete;

public:
	static const char* GetTitle() { return "Flickering Research"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};