#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class ConsoleScene
	{
	private:
		ConsoleScene() = delete;

	public:
		static const char* GetTitle() { return "Console"; }
		static MenuUp Create( Director& director );
	};
}