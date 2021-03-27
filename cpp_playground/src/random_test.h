#pragma once

namespace random_test
{
	class  Basic
	{
	public:
		static const char* GetTitle() { return "Random : Basic"; }
		static void Do();
	};



	class  StatusSaveAndLoad
	{
	public:
		static const char* GetTitle() { return "Random : Status Save And Load"; }
		static void Do();
	};
}