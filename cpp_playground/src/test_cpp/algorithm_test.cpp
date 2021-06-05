#include "pch.h"
#include "algorithm_test.h"

#include <numeric>

#include "base/r2_eTestResult.h"

namespace algorithm_test
{
	r2::iTest::TitleFunc Accumulate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Accumulate : Sum";
		};
	}
	r2::iTest::DoFunc Accumulate::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "# Sum" << r2::linefeed;
				std::cout << r2::linefeed;

				std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

				const int sum = std::accumulate( v.begin(), v.end(), 0 );

				std::cout << r2::tab << "+ Variable" << r2::linefeed;
				std::cout << r2::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Process" << r2::linefeed;
				std::cout << r2::tab2 << "const int sum = std::accumulate( v.begin(), v.end(), 0 );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Result" << r2::linefeed;
				std::cout << r2::tab2 << sum << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}