#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class AlgorithmMenu
	{
	private:
		AlgorithmMenu() = delete;

	public:
		static const char* GetTitle() { return "Algorithm"; }
		static MenuUp Create( Director& director );
	};
}