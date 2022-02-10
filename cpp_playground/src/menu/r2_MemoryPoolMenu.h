#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class MemoryPoolMenu
	{
	private:
		MemoryPoolMenu() = delete;

	public:
		static const char* GetTitle() { return "Memory Pool( Inprogress )"; }
		static MenuUp Create( Director& director );
	};
}