#pragma once

namespace template_meta_programming_test
{
	class CalculateFactorial
	{
	public:
		static const char* GetTitle() { return "TMP : Factorial"; }
		static void Do();
	};
}