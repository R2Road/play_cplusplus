#include "template_meta_programming_test.h"

#include <iostream>
#include <string>

namespace
{
	template<int N>
	void FactorialPrinter()
	{
		std::cout << N << " * ";
		FactorialPrinter<N - 1>();
	};

	template<>
	void FactorialPrinter<1>()
	{
		std::cout << 1 << std::endl;
	};


	template<int N>
	struct Factorial
	{
		static const int f = N * Factorial<N - 1>::f;
	};

	template<>
	struct Factorial<1>
	{
		static const int f = 1;
	};
}
namespace template_meta_programming_test
{
	void CalculateFactorial::Do()
	{
		std::cout << "== TMP : Calculate Factorial ==" << std::endl;

		{
			std::cout << "\t" << "+ Factorial<2>::f" << std::endl;

			std::cout << "\t\t" << "calc : ";
			FactorialPrinter<2>();
			std::cout << "\t\t" << "result : " << Factorial<2>::f << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ Factorial<4>::f" << std::endl;

			std::cout << "\t\t" << "calc : ";
			FactorialPrinter<4>();
			std::cout << "\t\t" << "result : " << Factorial<4>::f << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ Factorial<10>::f" << std::endl;

			std::cout << "\t\t" << "calc : ";
			FactorialPrinter<10>();
			std::cout << "\t\t" << "result : " << Factorial<10>::f << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}





namespace
{
	template<int N>
	struct ConvertInteger2String_1
	{
		static std::string c;
	};
	template<int N> std::string ConvertInteger2String_1<N>::c = std::to_string( N );
}
namespace template_meta_programming_test
{
	void Integer2String::Do()
	{
		std::cout << "== TMP : Integer 2 String ==" << std::endl;

		{
			std::cout << "\t\t" << "result : " << ConvertInteger2String_1<2>::c.c_str() << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}
