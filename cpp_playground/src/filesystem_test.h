#pragma once

namespace filesystem_test
{
	class CurrentDirectory
	{
	public:
		static const char* GetTitle() { return "File System : Current Directory"; }
		static void Do();
	};
}