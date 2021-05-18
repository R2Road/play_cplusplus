#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class RendererScene
	{
	private:
		RendererScene() = delete;

	public:
		static const char* GetTitle() { return "Renderer"; }
		static MenuUp Create( Director& director );
	};
}