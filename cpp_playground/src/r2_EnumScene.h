#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class EnumScene
	{
	private:
		EnumScene() = delete;

	public:
		static const char* GetTitle() { return "Enum"; }
		static SceneUp Create( Director& director );
	};
}