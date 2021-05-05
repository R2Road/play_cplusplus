#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class LambdaMenu
	{
	private:
		LambdaMenu() = delete;

	public:
		static const char* GetTitle() { return "Lambda"; }
		static SceneUp Create( Director& director );
	};
}