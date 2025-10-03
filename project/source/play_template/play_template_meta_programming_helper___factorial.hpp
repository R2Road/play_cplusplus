#pragma once

namespace play_template_meta_programming_01
{
	template<int N>
	struct Helper_Factorial
	{
		static const int f = N * Helper_Factorial<N - 1>::f;
	};

	template<>
	struct Helper_Factorial<1>
	{
		static const int f = 1;
	};
}