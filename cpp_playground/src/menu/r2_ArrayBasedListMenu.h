#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class ArrayBasedListMenu
	{
	private:
		ArrayBasedListMenu() = delete;

	public:
		static const char* GetTitle() { return "Array Based List"; }
		static MenuUp Create( Director& director );
	};
}