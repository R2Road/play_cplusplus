#include "pch.h"
#include "template_practice_part_02_test.h"

#include "r2_eTestResult.h"

namespace template_practice_part_02_test
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

	const r2::iNode::TitleFunc GreatestCommonDivisor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Template : Greatest Common Divisor";
		};
	}
	const r2::iNode::DoFunc GreatestCommonDivisor::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

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