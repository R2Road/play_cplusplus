#include "pch.h"
#include "algorithm_insertion_sort_test.h"

#include <array>

#include "base/r2_eTestResult.h"
#include "util/r2util_StopWatch.h"

namespace algorithm_insertion_sort_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Insertion Sort";
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
				std::cout << r2::tab << "+ Case" << r2::linefeed2;

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

				std::cout << r2::tab2;
				for( const auto a : temp_container )
				{
					std::cout << a << r2::tab;
				}
				std::cout << r2::linefeed;

				std::cout << r2::tab2;
				stop_watch.PrintLog_All();
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show" << r2::linefeed2;

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

				int key = 0;
				int compare_index = 0;
				for( int key_index = 1; temp_container.size() > key_index; ++key_index )
				{
					key = temp_container[key_index];
					compare_index = key_index - 1;

					std::cout << r2::tab2 << "start" << r2::linefeed;
					std::cout << r2::tab2 << "key : " << key << r2::tab2 << "key index : " << key_index << r2::tab << "compare index : " << compare_index << r2::linefeed;

					while( 0 <= compare_index && temp_container[compare_index] > key )
					{
						temp_container[compare_index + 1] = temp_container[compare_index]; // shift

						//
						//
						//
						std::cout << r2::tab2;
						for( const auto a : temp_container )
						{
							std::cout << a << r2::tab;
						}
						std::cout << "shift : index - " << compare_index << " > " << ( compare_index + 1 ) << r2::linefeed;

						--compare_index;
					}

					temp_container[compare_index + 1] = key;

					//
					//
					//
					std::cout << r2::linefeed;
					std::cout << r2::tab2;
					for( const auto a : temp_container )
					{
						std::cout << a << r2::tab;
					}
					std::cout << "insert : target index - " << ( compare_index + 1 ) << r2::linefeed2;
				}

				
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}