#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

namespace r2
{
	class AlgorithmMenu
	{
	private:
		AlgorithmMenu() = delete;

	public:
		static const char* GetTitle() { return "Algorithm"; }
		static r2cm::MenuUp Create( r2cm::Director& director );
	};
}