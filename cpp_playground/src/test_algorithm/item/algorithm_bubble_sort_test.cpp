#include "algorithm_bubble_sort_test.h"

#include <array>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_StopWatch.h"

namespace algorithm_bubble_sort_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Bubble Sort";
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
				std::cout << r2cm::tab << "+ Case 1" << r2cm::linefeed2;

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
				std::cout << r2cm::tab << "+ Show : Case 1" << r2cm::linefeed2;

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

				for( int i = 0, temp = 0; temp_container.size() - 1 > i; ++i )
				{
					std::cout << r2cm::tab2 << "range : 0 ~ " << ( temp_container.size() - i - 1 ) << r2cm::linefeed;

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
							std::cout << r2cm::tab2;
							for( const auto a : temp_container )
							{
								std::cout << a << r2cm::tab;
							}
							std::cout << r2cm::tab2 << " swap : " << temp_container[j] << " <> " << temp_container[j + 1] << r2cm::linefeed;
						}
					}

					//
					//
					//
					std::cout << r2cm::linefeed3;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}