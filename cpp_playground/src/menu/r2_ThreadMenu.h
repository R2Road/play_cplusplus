#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class ThreadMenu
	{
	private:
		ThreadMenu() = delete;

	public:
		static const char* GetTitle() { return "Thread"; }
		static MenuUp Create( Director& director );
	};
}