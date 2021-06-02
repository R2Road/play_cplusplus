#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class LambdaMenu
	{
	private:
		LambdaMenu() = delete;

	public:
		static const char* GetTitle() { return "Lambda"; }
		static MenuUp Create( Director& director );
	};
}