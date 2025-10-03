#pragma once

#include "r2tm/r2tm_ostream.hpp"

namespace play_template_meta_programming_01
{
	template<int N>
	void Helper_FactorialPrinter()
	{
		std::cout << N << " * ";
		Helper_FactorialPrinter<N - 1>();
	};

	template<>
	void Helper_FactorialPrinter<1>()
	{
		std::cout << 1 << r2tm::linefeed;
	};
}