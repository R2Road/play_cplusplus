#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class RandomScene
	{
	private:
		RandomScene() = delete;

	public:
		static const char* GetTitle() { return "Random"; }
		static SceneUp Create( Director& director );
	};
}