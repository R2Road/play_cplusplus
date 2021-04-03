#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director
	{
	public:
		Director();

		template<typename T>
		void Setup()
		{
			mScene.reset( new ( std::nothrow ) T );
		}

		bool Update();

	private:
		SceneUp mScene;
	};
}