#include "pch.h"
#include "std_array_test.h"

#include <array>

#include "base/r2_eTestResult.h"

namespace std_array_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array : Declaration";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;

			{
				std::array<int, 3u> test_array;
				std::cout << r2::tab2 << "std::array<int, 3u> test_array;" << r2::linefeed2;
			}

			{
				std::array<int, 3u> test_array{ { 1, 2, 3 } };
				std::cout << r2::tab2 << "std::array<int, 3u> test_array{ { 1, 2, 3 } };" << r2::linefeed2;
			}

			{
				std::array<int, 3u> test_array = { 1, 2, 3 };
				std::cout << r2::tab2 << "std::array<int, 3u> test_array = { 1, 2, 3 };" << r2::linefeed2;
			}

			{
				std::array aa{ 1, 2, 3 };
				std::cout << r2::tab2 << "std::array aa{ 1, 2, 3 };" << r2::linefeed;
				std::cout << r2::tab2 << "* Note : Since c++17" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}