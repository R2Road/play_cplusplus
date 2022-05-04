#pragma once

#include <memory>

namespace r2cm
{
	using MenuUp = std::unique_ptr<class Menu>;

	class Director;
}

class TestAlgorithmMenu
{
private:
	TestAlgorithmMenu() = delete;

public:
	static const char* GetTitle() { return "Test Algorithm Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};