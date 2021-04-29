#include "pch.h"
#include "template_meta_programming_01_test.h"

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
			return "Factorial";
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
			return "Greatest Common Divisor";
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



namespace template_meta_programming_test
{
	template<int N, int D>
	struct Ratio_Step_0
	{
		static const int Numerator = N;
		static const int Denominator = D;
	};


	const r2::iTest::TitleFunc RatioBasic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Ratio Basic";
		};
	}
	const r2::iTest::DoFunc RatioBasic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				Ratio_Step_0<7, 4> ratio;

				std::cout << "\t + " << "RatioBasic<7, 4> ratio;" << r2::linefeed;
				std::cout << "\t\t - " << ratio.Numerator << " / " << ratio.Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace template_meta_programming_test
{
	template<class Ratio1, class Ratio2>
	struct RatioOperator_Sum
	{
		static const Ratio_Step_0<
			Ratio1::Numerator * Ratio2::Denominator + Ratio2::Numerator * Ratio1::Denominator
			, Ratio1::Denominator * Ratio2::Denominator
		> ratio;
	};


	const r2::iTest::TitleFunc RatioSum::GetTitleFunction() const
	{
		return []()->const char* { return "Ratio Sum"; };
	}
	const r2::iTest::DoFunc RatioSum::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				using ratio1 = Ratio_Step_0<7, 4>;
				using ratio2 = Ratio_Step_0<3, 2>;
				using ratio_operator_sum = RatioOperator_Sum<ratio1, ratio2>;

				std::cout << "\t" << "using ratio1 = Ratio_Step_0<7, 4>;" << r2::linefeed;
				std::cout << "\t" << "using ratio2 = Ratio_Step_0<3, 2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t" << "using ratio_operator_sum = RatioOperator_Sum<ratio1, ratio2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - Result : " << ratio_operator_sum::ratio.Numerator << " / " << ratio_operator_sum::ratio.Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}
