#include "pch.h"
#include "template_meta_programming_test.h"

#include <string>

#include "r2_eTestResult.h"

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
		std::cout << 1 << r2::linefeed;
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
	const r2::iTest::TitleFunc CalculateFactorial::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Factorial";
		};
	}
	const r2::iTest::DoFunc CalculateFactorial::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Factorial<2>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<2>();
				std::cout << "\t\t" << "result : " << Factorial<2>::f << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Factorial<4>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<4>();
				std::cout << "\t\t" << "result : " << Factorial<4>::f << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Factorial<10>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<10>();
				std::cout << "\t\t" << "result : " << Factorial<10>::f << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace template_meta_programming_test
{
	template<int A, int B>
	struct GCDCalculator
	{
		static const int value = GCDCalculator<B, A % B>::value;
	};

	template<int A>
	struct GCDCalculator<A, 0>
	{
		static const int value = A;
	};

	const r2::iTest::TitleFunc GreatestCommonDivisor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Template : Greatest Common Divisor";
		};
	}
	const r2::iTest::DoFunc GreatestCommonDivisor::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t + " << "GCDCalculator<9, 3>::value" << r2::linefeed;
				std::cout << "\t\t - Result : " << GCDCalculator<9, 3>::value << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t + " << "GCDCalculator<5, 2>::value" << r2::linefeed;
				std::cout << "\t\t - Result : " << GCDCalculator<5, 2>::value << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}
