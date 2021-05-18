#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class EnumScene
	{
	private:
		EnumScene() = delete;

	public:
		static const char* GetTitle() { return "Enum"; }
		static MenuUp Create( Director& director );
	};
}