#pragma once

#include <memory>

namespace r2
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;

	class FileSystemScene
	{
	private:
		FileSystemScene() = delete;

	public:
		static const char* GetTitle() { return "File System"; }
		static MenuUp Create( Director& director );
	};
}