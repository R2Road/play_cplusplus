#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class NewScene
	{
	private:
		NewScene() = delete;

	public:
		static const char* GetTitle() { return "New"; }
		static SceneUp Create( Director& director );
	};
}