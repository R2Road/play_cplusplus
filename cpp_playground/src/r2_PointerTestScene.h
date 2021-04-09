#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class PointerTestScene
	{
	private:
		PointerTestScene() = delete;

	public:
		static SceneUp Create( Director& director );
	};
}