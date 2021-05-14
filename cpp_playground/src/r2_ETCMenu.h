#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class ETCMenu
	{
	private:
		ETCMenu() = delete;

	public:
		static const char* GetTitle() { return "ETC"; }
		static SceneUp Create( Director& director );
	};
}