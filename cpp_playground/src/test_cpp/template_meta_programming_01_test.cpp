#include "pch.h"
#include "template_meta_programming_01_test.h"

#include "base/r2_eTestEndAction.h"

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
	r2::iItem::TitleFuncT CalculateFactorial::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Factorial";
		};
	}
	r2::iItem::DoFunc CalculateFactorial::GetDoFunction()
	{
		return []()->r2::eTestEndAction
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

			return r2::eTestEndAction::Pause;
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

	r2::iItem::TitleFuncT GreatestCommonDivisor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Greatest Common Divisor";
		};
	}
	r2::iItem::DoFunc GreatestCommonDivisor::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

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

			return r2::eTestEndAction::Pause;
		};
	}
}



namespace template_meta_programming_test
{
	template<int N, int D>
	struct Ratio_VER0
	{
		static const int Numerator = N;
		static const int Denominator = D;
	};


	r2::iItem::TitleFuncT BasicRatio::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic Ratio";
		};
	}
	r2::iItem::DoFunc BasicRatio::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				Ratio_VER0<7, 4> ratio;

				std::cout << "\t + " << "Ratio_VER0<7, 4> ratio;" << r2::linefeed;
				std::cout << "\t\t - " << ratio.Numerator << " / " << ratio.Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}



namespace template_meta_programming_test
{
	template<class Ratio1, class Ratio2>
	struct Ratio_VER0_Operator_Sum
	{
		static const Ratio_VER0<
			Ratio1::Numerator * Ratio2::Denominator + Ratio2::Numerator * Ratio1::Denominator
			, Ratio1::Denominator * Ratio2::Denominator
		> ratio;
	};


	r2::iItem::TitleFuncT SumBasicRatio::GetTitleFunction() const
	{
		return []()->const char* { return "Sum Basic Ratio"; };
	}
	r2::iItem::DoFunc SumBasicRatio::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				using ratio1 = Ratio_VER0<7, 4>;
				using ratio2 = Ratio_VER0<3, 2>;
				using ratio_operator_sum = Ratio_VER0_Operator_Sum<ratio1, ratio2>;

				std::cout << "\t" << "using ratio1 = Ratio_VER0<7, 4>;" << r2::linefeed;
				std::cout << "\t" << "using ratio2 = Ratio_VER0<3, 2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t" << "using ratio_operator_sum = Ratio_VER0_Operator_Sum<ratio1, ratio2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - Result : " << ratio_operator_sum::ratio.Numerator << " / " << ratio_operator_sum::ratio.Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}



namespace template_meta_programming_test
{
	template<int N, int D>
	struct Ratio_VER1
	{
		using gcd = GCDCalculator<N, D>;

		static const int Numerator = N / gcd::value;
		static const int Denominator = D / gcd::value;
	};


	r2::iItem::TitleFuncT RatioWithGCD::GetTitleFunction() const
	{
		return []()->const char* { return "Ratio with GCD"; };
	}
	r2::iItem::DoFunc RatioWithGCD::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				using ratio = Ratio_VER1<12, 3>;

				std::cout << "\t" << "using ratio1 = Ratio_VER1<12, 3>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - GCD : " << ratio::gcd::value << r2::linefeed;
				std::cout << "\t\t - Result : " << ratio::Numerator << " / " << ratio::Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			{
				using ratio = Ratio_VER1<36, 20>;

				std::cout << "\t" << "using ratio1 = Ratio_VER1<36, 20>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - GCD : " << ratio::gcd::value << r2::linefeed;
				std::cout << "\t\t - Result : " << ratio::Numerator << " / " << ratio::Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}



namespace template_meta_programming_test
{
	template<class Ratio1, class Ratio2>
	struct Ratio_VER1_Operator_Sum
	{
		using orig = Ratio_VER0<
			Ratio1::Numerator * Ratio2::Denominator + Ratio2::Numerator * Ratio1::Denominator
			, Ratio1::Denominator * Ratio2::Denominator
		>;

		using gcd = GCDCalculator<orig::Numerator, orig::Denominator>;

		static const int Numerator = orig::Numerator / gcd::value;
		static const int Denominator = orig::Denominator / gcd::value;
	};


	r2::iItem::TitleFuncT SumRatioWithGCD::GetTitleFunction() const
	{
		return []()->const char* { return "Sum Ratio with GCD"; };
	}
	r2::iItem::DoFunc SumRatioWithGCD::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				using ratio1 = Ratio_VER1<7, 4>;
				using ratio2 = Ratio_VER1<3, 2>;
				using ratio_operator_sum = Ratio_VER1_Operator_Sum<ratio1, ratio2>;

				std::cout << "\t" << "using ratio1 = Ratio_VER1<7, 4>;" << r2::linefeed;
				std::cout << "\t" << "using ratio2 = Ratio_VER1<3, 2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t" << "using ratio_operator_sum = Ratio_VER1_Operator_Sum<ratio1, ratio2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - Original : " << ratio_operator_sum::orig::Numerator << " / " << ratio_operator_sum::orig::Denominator << r2::linefeed;
				std::cout << "\t\t - GCD : " << ratio_operator_sum::gcd::value << r2::linefeed;
				std::cout << "\t\t - Result : " << ratio_operator_sum::Numerator << " / " << ratio_operator_sum::Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}



namespace template_meta_programming_test
{
	r2::iItem::TitleFuncT SumRatioAndOperator1::GetTitleFunction() const
	{
		return []()->const char* { return "Sum Ratio and Operator 1"; };
	}
	r2::iItem::DoFunc SumRatioAndOperator1::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				using ratio1 = Ratio_VER1<7, 4>;
				using ratio2 = Ratio_VER1<3, 2>;
				using ratio_operator_sum = Ratio_VER1_Operator_Sum<ratio1, ratio2>;

				std::cout << "\t" << "using ratio1 = Ratio_VER1<7, 4>;" << r2::linefeed;
				std::cout << "\t" << "using ratio2 = Ratio_VER1<3, 2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t" << "using ratio_operator_sum = Ratio_VER1_Operator_Sum<ratio1, ratio2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - Original : " << ratio_operator_sum::orig::Numerator << " / " << ratio_operator_sum::orig::Denominator << r2::linefeed;
				std::cout << "\t\t - GCD : " << ratio_operator_sum::gcd::value << r2::linefeed;
				std::cout << "\t\t - Result : " << ratio_operator_sum::Numerator << " / " << ratio_operator_sum::Denominator << r2::linefeed;


				std::cout << r2::linefeed << r2::linefeed;


				using ratio_operator_sum_2 = Ratio_VER1_Operator_Sum<ratio1, ratio_operator_sum>;

				std::cout << "\t" << "using ratio_operator_sum_2 = Ratio_VER1_Operator_Sum<ratio1, ratio_operator_sum>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - Original : " << ratio_operator_sum_2::orig::Numerator << " / " << ratio_operator_sum_2::orig::Denominator << r2::linefeed;
				std::cout << "\t\t - GCD : " << ratio_operator_sum_2::gcd::value << r2::linefeed;
				std::cout << "\t\t - Result : " << ratio_operator_sum_2::Numerator << " / " << ratio_operator_sum_2::Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}



namespace template_meta_programming_test
{
	template<class Ratio1, class Ratio2>
	struct Ratio_VER1_Operator_Sum2
	{
		using orig = Ratio_VER0<
			Ratio1::Numerator * Ratio2::Denominator + Ratio2::Numerator * Ratio1::Denominator
			, Ratio1::Denominator * Ratio2::Denominator
		>;

		using ratio = Ratio_VER1<orig::Numerator, orig::Denominator>;
	};

	template<class Ratio1, class Ratio2>
	struct Ratio_VER1_Operator_Sum2_Result : Ratio_VER1_Operator_Sum2<Ratio1, Ratio2>::ratio {};

	r2::iItem::TitleFuncT SumRatioAndOperator2::GetTitleFunction() const
	{
		return []()->const char* { return "Sum Ratio and Operator 2"; };
	}
	r2::iItem::DoFunc SumRatioAndOperator2::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				using ratio1 = Ratio_VER1<7, 4>;
				using ratio2 = Ratio_VER1<3, 2>;
				using ratio_operator_sum = Ratio_VER1_Operator_Sum2<ratio1, ratio2>;

				std::cout << "\t" << "using ratio1 = Ratio_VER1<7, 4>;" << r2::linefeed;
				std::cout << "\t" << "using ratio2 = Ratio_VER1<3, 2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t" << "using ratio_operator_sum = Ratio_VER1_Operator_Sum2_Result<ratio1, ratio2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - Original : " << ratio_operator_sum::orig::Numerator << " / " << ratio_operator_sum::orig::Denominator << r2::linefeed;
				std::cout << "\t\t - Result : " << ratio_operator_sum::ratio::Numerator << " / " << ratio_operator_sum::ratio::Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			{
				using ratio1 = Ratio_VER1<7, 4>;
				using ratio2 = Ratio_VER1<3, 2>;
				using ratio_operator_sum = Ratio_VER1_Operator_Sum2_Result<ratio1, ratio2>;

				std::cout << "\t" << "using ratio1 = Ratio_VER1<7, 4>;" << r2::linefeed;
				std::cout << "\t" << "using ratio2 = Ratio_VER1<3, 2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t" << "using ratio_operator_sum = Ratio_VER1_Operator_Sum2_Result<ratio1, ratio2>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - Result : " << ratio_operator_sum::Numerator << " / " << ratio_operator_sum::Denominator << r2::linefeed;


				std::cout << r2::linefeed << r2::linefeed;


				using ratio_operator_sum_2 = Ratio_VER1_Operator_Sum2_Result<ratio1, ratio_operator_sum>;

				std::cout << "\t" << "using ratio_operator_sum = Ratio_VER1_Operator_Sum2_Result<ratio1, ratio_operator_sum>;" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t\t - Result : " << ratio_operator_sum_2::Numerator << " / " << ratio_operator_sum_2::Denominator << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}
