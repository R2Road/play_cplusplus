#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class Scene>;

	class Director;

	class FileSystemScene
	{
	private:
		FileSystemScene() = delete;

	public:
		static const char* GetTitle() { return "File System"; }
		static SceneUp Create( Director& director );
	};
}