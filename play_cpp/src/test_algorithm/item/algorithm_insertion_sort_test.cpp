#include "algorithm_insertion_sort_test.h"

#include <array>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_StopWatch.h"

namespace algorithm_insertion_sort_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Insertion Sort";
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
				std::cout << r2tm::tab << "+ Case" << r2tm::linefeed2;

				auto temp_container = test_container;

				stop_watch.Start();
				int key = 0;
				int compare_index = 0;
				for( int key_index = 1; temp_container.size() > key_index; ++key_index )
				{
					key = temp_container[key_index];

					compare_index = key_index - 1;

					while( 0 <= compare_index && temp_container[compare_index] > key )
					{
						temp_container[compare_index + 1] = temp_container[compare_index]; // shift

						--compare_index;
					}

					temp_container[compare_index + 1] = key;
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
				std::cout << r2tm::tab << "+ Show" << r2tm::linefeed2;

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

				int key = 0;
				int compare_index = 0;
				for( int key_index = 1; temp_container.size() > key_index; ++key_index )
				{
					key = temp_container[key_index];
					compare_index = key_index - 1;

					std::cout << r2tm::tab2 << "start" << r2tm::linefeed;
					std::cout << r2tm::tab2 << "key : " << key << r2tm::tab2 << "key index : " << key_index << r2tm::tab << "compare index : " << compare_index << r2tm::linefeed;

					while( 0 <= compare_index && temp_container[compare_index] > key )
					{
						temp_container[compare_index + 1] = temp_container[compare_index]; // shift

						//
						//
						//
						std::cout << r2tm::tab2;
						for( const auto a : temp_container )
						{
							std::cout << a << r2tm::tab;
						}
						std::cout << "shift index : " << compare_index << " > " << ( compare_index + 1 ) << r2tm::linefeed;

						--compare_index;
					}

					temp_container[compare_index + 1] = key;

					//
					//
					//
					std::cout << r2tm::linefeed;
					std::cout << r2tm::tab2;
					for( const auto a : temp_container )
					{
						std::cout << a << r2tm::tab;
					}
					std::cout << "insert : target index - " << ( compare_index + 1 ) << r2tm::linefeed2;
				}

				
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}