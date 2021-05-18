#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class RandomScene
	{
	private:
		RandomScene() = delete;

	public:
		static const char* GetTitle() { return "Random"; }
		static MenuUp Create( Director& director );
	};
}