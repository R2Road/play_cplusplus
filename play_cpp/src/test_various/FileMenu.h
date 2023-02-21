#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class FileMenu
{
private:
	FileMenu() = delete;

public:
	static const char* GetTitle() { return "File Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};