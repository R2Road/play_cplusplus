#include "template_meta_programming_test.h"

#include <iostream>

namespace
{
	template<int N>
	int Factorial()
	{
		return ( N * Factorial<N - 1>() );
	};

	template<>
	int Factorial<1>()
	{
		return 1;
	};
}

namespace template_meta_programming_test
{
	void CalculateFactorial::Do()
	{
		std::cout << "== TMP : Calculate Factorial ==" << std::endl;

		{
			std::cout << "\t" << "+ Factorial<2>::f" << std::endl;

			std::cout << "\t\t" << "result : " << Factorial<2>() << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ Factorial<4>::f" << std::endl;

			std::cout << "\t\t" << "result : " << Factorial<4>() << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ Factorial<10>::f" << std::endl;

			std::cout << "\t\t" << "result : " << Factorial<10>() << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}
