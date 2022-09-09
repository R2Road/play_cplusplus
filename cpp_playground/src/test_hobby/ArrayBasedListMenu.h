#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class ListBasedOnArrayMenu
{
private:
	ListBasedOnArrayMenu() = delete;

public:
	static const char* GetTitle() { return "List Based On Array Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};