#include "pch.h"
#include "algorithm_bubble_sort_test.h"

#include <array>

#include "base/r2_eTestResult.h"
#include "util/r2util_StopWatch.h"

namespace algorithm_bubble_sort_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Bubble Sort";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			const std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Case 1" << r2::linefeed2;

				auto temp_container = test_container;

				stop_watch.Start();
				for( int i = 0, temp = 0; temp_container.size() - 1 > i; ++i )
				{
					for( int j = 0 ; temp_container.size() - i - 1 > j; ++j )
					{
						if( temp_container[j] > temp_container[j + 1] )
						{
							temp = temp_container[j];
							temp_container[j] = temp_container[j + 1];
							temp_container[j + 1] = temp;
						}
					}
				}
				stop_watch.Stop();

				std::cout << r2::tab2;
				for( const auto a : temp_container )
				{
					std::cout << a << r2::tab;
				}
				std::cout << r2::linefeed;

				std::cout << r2::tab2;
				stop_watch.PrintElapsedTime_All();
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show : Case 1" << r2::linefeed2;

				auto temp_container = test_container;

				//
				//
				//
				std::cout << r2::tab2;
				for( const auto a : temp_container )
				{
					std::cout << a << r2::tab;
				}
				std::cout << r2::linefeed2;

				for( int i = 0, temp = 0; temp_container.size() - 1 > i; ++i )
				{
					std::cout << r2::tab2 << "range : 0 ~ " << ( temp_container.size() - i - 1 ) << r2::linefeed;

					for( int j = 0; temp_container.size() - i - 1 > j; ++j )
					{
						if( temp_container[j] > temp_container[j + 1] )
						{
							temp = temp_container[j];
							temp_container[j] = temp_container[j + 1];
							temp_container[j + 1] = temp;

							//
							//
							//
							std::cout << r2::tab2;
							for( const auto a : temp_container )
							{
								std::cout << a << r2::tab;
							}
							std::cout << r2::tab2 << " swap : " << temp_container[j] << " <> " << temp_container[j + 1] << r2::linefeed;
						}
					}

					//
					//
					//
					std::cout << r2::linefeed3;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}