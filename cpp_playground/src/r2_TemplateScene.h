#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class TemplateScene
	{
	private:
		TemplateScene() = delete;

	public:
		static const char* GetTitle() { return "Template"; }
		static SceneUp Create( Director& director );
	};
}