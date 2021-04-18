#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class ConsoleScene
	{
	private:
		ConsoleScene() = delete;

	public:
		static const char* GetTitle() { return "Console"; }
		static SceneUp Create( Director& director );
	};
}