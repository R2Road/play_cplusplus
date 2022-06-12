#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;
	class Director;
}

class FileMenu
{
private:
	FileMenu() = delete;

public:
	static const char* GetTitle() { return "File"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};