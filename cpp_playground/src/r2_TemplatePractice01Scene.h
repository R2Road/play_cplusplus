#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class TemplatePractice01Scene
	{
	private:
		TemplatePractice01Scene() = delete;

	public:
		static const char* GetTitle() { return "Template Practice 01"; }
		static SceneUp Create( Director& director );
	};
}