#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class MemoryScene
	{
	private:
		MemoryScene() = delete;

	public:
		static const char* GetTitle() { return "Memory"; }
		static SceneUp Create( Director& director );
	};
}