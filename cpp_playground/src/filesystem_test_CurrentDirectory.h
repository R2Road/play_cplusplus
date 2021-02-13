#pragma once

namespace filesystem_test
{
	class CurrentDirectory
	{
	public:
		static const char* GetTitle() { return "CurrentDirectory"; }
		static void Do();
	};
}