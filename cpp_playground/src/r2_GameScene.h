#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class GameScene
	{
	private:
		GameScene() = delete;

	public:
		static const char* GetTitle() { return "Game"; }
		static SceneUp Create( Director& director );
	};
}