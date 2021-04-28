#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class RendererScene
	{
	private:
		RendererScene() = delete;

	public:
		static const char* GetTitle() { return "Renderer"; }
		static SceneUp Create( Director& director );
	};
}