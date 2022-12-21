#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class FSM_V1_Menu
{
private:
	FSM_V1_Menu() = delete;

public:
	static const char* GetTitle() { return "fsm v1 Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};