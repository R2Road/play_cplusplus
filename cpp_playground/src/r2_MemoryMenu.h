#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class MemoryMenu
	{
	private:
		MemoryMenu() = delete;

	public:
		static const char* GetTitle() { return "Memory"; }
		static MenuUp Create( Director& director );
	};
}