#include "pch.h"
#include "performance_1_test.h"

#include <conio.h>
#include <memory>
#include <numeric>

#include "base/r2_eTestResult.h"

#include "util/r2util_StopWatch.h"

namespace performance_1_test
{
	r2::iTest::TitleFunc IncrementOperator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "++Operator";
		};
	}
	r2::iTest::DoFunc IncrementOperator::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			const int attempt_count = std::numeric_limits<int>::max() / 1000;

			{
				std::cout << r2::tab << "+ Int" << " ++ X " << attempt_count << r2::linefeed2;

				int test_int = 0;
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
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
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Int*" << " ++ X " << attempt_count << r2::linefeed2;

				int test_int = 0;
				int* test_pointer = &test_int;
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
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
					std::cout << r2::tab2 << *test_pointer;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ new Int*" << " ++ X " << attempt_count << r2::linefeed2;

				std::unique_ptr<int> test_unique_pointer( new int( 0 ) );
				int* test_pointer = test_unique_pointer.get();
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
				{
					*test_pointer = 0;

					stop_watch.Start();
					while( attempt_count > *test_pointer )
					{
						++( *test_pointer );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog();
					std::cout << r2::tab2 << *test_pointer;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Int Up" << " ++ X " << attempt_count << r2::linefeed2;

				std::unique_ptr<int> test_pointer( new int( 0 ) );
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
				{
					*test_pointer = 0;

					stop_watch.Start();
					while( attempt_count > *test_pointer )
					{
						++( *test_pointer );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog();
					std::cout << r2::tab2 << *test_pointer;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Int Sp" << " ++ X " << attempt_count << r2::linefeed2;

				std::shared_ptr<int> test_pointer( new int( 0 ) );
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
				{
					*test_pointer = 0;

					stop_watch.Start();
					while( attempt_count > *test_pointer )
					{
						++( *test_pointer );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog();
					std::cout << r2::tab2 << *test_pointer;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Loop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop";
		};
	}
	r2::iTest::DoFunc Loop::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			const int attempt_count = std::numeric_limits<int>::max() / 10;

			{
				std::cout << r2::tab << "+ For" << " ++ X " << attempt_count << r2::linefeed2;

				int test_int = 0;
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					for( ; attempt_count > test_int; )
					{
						++test_int;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ While" << " ++ X " << attempt_count << r2::linefeed2;

				int test_int = 0;
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
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
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}