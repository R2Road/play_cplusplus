#pragma once

#include "r2tm/r2tm_ostream.hpp"

namespace play_template_meta_programming_01
{
	template<int N>
	void Helper_Factorial_ProcessPrinter();



	template<int N>
	void Helper_Factorial_FormatPrinter()
	{
		Helper_Factorial_ProcessPrinter<N>();
		std::cout << " * ";
	};



	template<int N>
	void Helper_Factorial_ProcessPrinter()
	{
		Helper_Factorial_FormatPrinter<N - 1>();
		std::cout << N;
	};

	template<>
	void Helper_Factorial_ProcessPrinter<1>()
	{
		std::cout << 1;
	};
}