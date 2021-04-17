#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class AlignScene
	{
	private:
		AlignScene() = delete;

	public:
		static const char* GetTitle() { return "Align"; }
		static SceneUp Create( Director& director );
	};
}