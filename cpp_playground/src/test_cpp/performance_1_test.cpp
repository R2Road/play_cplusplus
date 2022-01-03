#include "pch.h"
#include "performance_1_test.h"

#include <array>
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
					stop_watch.PrintLog_NanoSeconds();
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
					stop_watch.PrintLog_NanoSeconds();
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
					stop_watch.PrintLog_NanoSeconds();
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
					stop_watch.PrintLog_NanoSeconds();
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
					stop_watch.PrintLog_NanoSeconds();
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

			const unsigned int attempt_count = std::numeric_limits<unsigned int>::max() / 10;

			{
				std::cout << r2::tab << "+ For" << " ++ X " << attempt_count << r2::linefeed2;

				unsigned int test_int = 0;
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
					stop_watch.PrintLog_NanoSeconds();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ While" << " ++ X " << attempt_count << r2::linefeed2;

				unsigned int test_int = 0;
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
					stop_watch.PrintLog_NanoSeconds();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc LoopWithArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop With Array";
		};
	}
	r2::iTest::DoFunc LoopWithArray::GetDoFunction()
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
}