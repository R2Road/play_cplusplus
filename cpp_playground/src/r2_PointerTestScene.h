#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class PointerTestScene
	{
	private:
		PointerTestScene() = delete;

	public:
		static const char* GetTitle() { return "Pointer"; }
		static MenuUp Create( Director& director );
	};
}