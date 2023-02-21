#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class Vector3Menu
{
private:
	Vector3Menu() = delete;

public:
	static const char* GetTitle() { return "Vector3 Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};