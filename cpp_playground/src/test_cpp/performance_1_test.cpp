#include "pch.h"
#include "performance_1_test.h"

#include <conio.h>
#include <numeric>

#include "base/r2_eTestResult.h"

#include "util/r2util_StopWatch.h"

namespace performance_1_test
{
	r2::iTest::TitleFunc Assignment_With_Pointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Assignment With Pointer";
		};
	}
	r2::iTest::DoFunc Assignment_With_Pointer::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			const int attempt_count = std::numeric_limits<int>::max() / 10;

			{
				std::cout << r2::tab << "+ Test with Int" << r2::linefeed;
				std::cout << r2::tab2 << "++ X " << attempt_count << r2::linefeed2;

				int test_int = 0;
				r2util::StopWatch stop_watch;

				for( int i = 0; 10 > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					while( attempt_count > test_int )
					{
						++test_int;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog();
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Test with Int*" << r2::linefeed;
				std::cout << r2::tab2 << "++ X " << attempt_count << r2::linefeed2;

				int test_int = 0;
				int* test_pointer = &test_int;
				r2util::StopWatch stop_watch;

				for( int i = 0; 10 > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					while( attempt_count > *test_pointer )
					{
						++( *test_pointer );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog();
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}