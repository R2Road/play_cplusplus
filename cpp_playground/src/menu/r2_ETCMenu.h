#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class ETCMenu
	{
	private:
		ETCMenu() = delete;

	public:
		static const char* GetTitle() { return "ETC"; }
		static MenuUp Create( Director& director );
	};
}