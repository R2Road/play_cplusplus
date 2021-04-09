#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class TemplateMetaProgrammingScene
	{
	private:
		TemplateMetaProgrammingScene() = delete;

	public:
		static SceneUp Create( Director& director );
	};
}