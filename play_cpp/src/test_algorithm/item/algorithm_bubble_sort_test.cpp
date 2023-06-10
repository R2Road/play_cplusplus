#include "algorithm_bubble_sort_test.h"

#include <array>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_StopWatch.h"

namespace algorithm_bubble_sort_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Bubble Sort";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2tm::StopWatch stop_watch;
			const std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };" << r2tm::linefeed;

			LS();

			{
				std::cout << r2tm::tab << "+ Case 1" << r2tm::linefeed2;

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

				std::cout << r2tm::tab2;
				for( const auto a : temp_container )
				{
					std::cout << a << r2tm::tab;
				}
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab2;
				stop_watch.PrintElapsedTime_All();
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Show : Case 1" << r2tm::linefeed2;

				auto temp_container = test_container;

				//
				//
				//
				std::cout << r2tm::tab2;
				for( const auto a : temp_container )
				{
					std::cout << a << r2tm::tab;
				}
				std::cout << r2tm::linefeed2;

				for( int i = 0, temp = 0; temp_container.size() - 1 > i; ++i )
				{
					std::cout << r2tm::tab2 << "range : 0 ~ " << ( temp_container.size() - i - 1 ) << r2tm::linefeed;

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
							std::cout << r2tm::tab2;
							for( const auto a : temp_container )
							{
								std::cout << a << r2tm::tab;
							}
							std::cout << r2tm::tab2 << " swap : " << temp_container[j] << " <> " << temp_container[j + 1] << r2tm::linefeed;
						}
					}

					//
					//
					//
					std::cout << r2tm::linefeed3;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}