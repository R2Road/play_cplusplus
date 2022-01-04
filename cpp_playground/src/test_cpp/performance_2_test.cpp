#include "pch.h"
#include "performance_2_test.h"

#include <array>
#include <vector>

#include "base/r2_eTestResult.h"

#include "util/r2util_StopWatch.h"

namespace performance_2_test
{
	r2::iTest::TitleFunc LoopWithBuildInArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop With Built-In Array";
		};
	}
	r2::iTest::DoFunc LoopWithBuildInArray::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			const unsigned int attempt_count = 100000;

			int test_container[attempt_count];
			std::fill_n( test_container, attempt_count, 1 );

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "const unsigned int attempt_count = " << attempt_count << ";" << r2::linefeed2;
			std::cout << r2::tab2 << "int test_container[attempt_count];" << r2::linefeed;
			std::cout << r2::tab2 << "std::fill_n( test_container, attempt_count, 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For" << r2::linefeed2;

				unsigned int test_int = 0;
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					for( unsigned int a = 0; attempt_count > a; ++a )
					{
						test_int += test_container[a];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog_NanoSeconds();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ While" << r2::linefeed2;

				unsigned int test_int = 0;
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					unsigned int a = 0;
					while( attempt_count > a )
					{
						test_int += test_container[a];

						++a;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog_NanoSeconds();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc LoopWithSTDArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop With std::array";
		};
	}
	r2::iTest::DoFunc LoopWithSTDArray::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			const unsigned int attempt_count = 100000;

			std::array<int, attempt_count> test_container;
			test_container.fill( 1 );

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "const unsigned int attempt_count = " << attempt_count << ";" << r2::linefeed2;
			std::cout << r2::tab2 << "std::array<int, attempt_count> test_container;" << r2::linefeed;
			std::cout << r2::tab2 << "test_container.fill( 1 );" << r2::linefeed2;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For"<< r2::linefeed2;

				unsigned int test_int = 0;
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					for( unsigned int a = 0; attempt_count > a; ++a )
					{
						test_int += test_container[a];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog_NanoSeconds();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ While" << r2::linefeed2;

				unsigned int test_int = 0;
				r2util::StopWatch stop_watch;

				for( int i = 0; 5 > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					unsigned int a = 0;
					while( attempt_count > a )
					{
						test_int += test_container[a];

						++a;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog_NanoSeconds();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc VectorIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "VectorIteration";
		};
	}
	r2::iTest::DoFunc VectorIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::vector<int> test_container( 100000, 1 );
			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::vector<int> test_container( 100000, 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( unsigned int cur = 0, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog_NanoSeconds();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintLog_NanoSeconds();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}