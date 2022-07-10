#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class STDFileSystemMenu
{
private:
	STDFileSystemMenu() = delete;

public:
	static const char* GetTitle() { return "std::filesystem Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};