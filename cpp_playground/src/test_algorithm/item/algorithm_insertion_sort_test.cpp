#include "algorithm_insertion_sort_test.h"

#include <array>

#include "r2cm/r2cm_ostream.h"
#include "utility/r2utility_StopWatch.h"

namespace algorithm_insertion_sort_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Insertion Sort";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			r2cm::StopWatch stop_watch;
			const std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Case" << r2cm::linefeed2;

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

				std::cout << r2cm::tab2;
				for( const auto a : temp_container )
				{
					std::cout << a << r2cm::tab;
				}
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2;
				stop_watch.PrintElapsedTime_All();
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Show" << r2cm::linefeed2;

				auto temp_container = test_container;

				//
				//
				//
				std::cout << r2cm::tab2;
				for( const auto a : temp_container )
				{
					std::cout << a << r2cm::tab;
				}
				std::cout << r2cm::linefeed2;

				int key = 0;
				int compare_index = 0;
				for( int key_index = 1; temp_container.size() > key_index; ++key_index )
				{
					key = temp_container[key_index];
					compare_index = key_index - 1;

					std::cout << r2cm::tab2 << "start" << r2cm::linefeed;
					std::cout << r2cm::tab2 << "key : " << key << r2cm::tab2 << "key index : " << key_index << r2cm::tab << "compare index : " << compare_index << r2cm::linefeed;

					while( 0 <= compare_index && temp_container[compare_index] > key )
					{
						temp_container[compare_index + 1] = temp_container[compare_index]; // shift

						//
						//
						//
						std::cout << r2cm::tab2;
						for( const auto a : temp_container )
						{
							std::cout << a << r2cm::tab;
						}
						std::cout << "shift index : " << compare_index << " > " << ( compare_index + 1 ) << r2cm::linefeed;

						--compare_index;
					}

					temp_container[compare_index + 1] = key;

					//
					//
					//
					std::cout << r2cm::linefeed;
					std::cout << r2cm::tab2;
					for( const auto a : temp_container )
					{
						std::cout << a << r2cm::tab;
					}
					std::cout << "insert : target index - " << ( compare_index + 1 ) << r2cm::linefeed2;
				}

				
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}