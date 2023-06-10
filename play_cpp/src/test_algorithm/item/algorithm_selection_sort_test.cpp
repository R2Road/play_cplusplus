#include "algorithm_selection_sort_test.h"

#include <array>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_StopWatch.h"

template<class _Elem, class _Traits, class ContainerT>
std::basic_ostream<_Elem, _Traits>& operator << ( std::basic_ostream<_Elem, _Traits>& _Ostr, const ContainerT& container )
{
	for( const auto a : container )
	{
		_Ostr << a << r2tm::tab;
	}

	return ( _Ostr );
}

namespace algorithm_selection_sort_test
{
	r2tm::TitleFunctionT Case1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Selection Sort : Case 1";
		};
	}
	r2tm::DoFunctionT Case1::GetDoFunction() const
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
				std::cout << r2tm::tab << "+ Case 1 : comparison and swap" << r2tm::linefeed2;

				auto temp_container = test_container;

				stop_watch.Start();
				int temp = 0;
				for( int i = 0; temp_container.size() - 1 > i; ++i )
				{
					for( int j = i + 1; temp_container.size() > j; ++j )
					{
						if( temp_container[i] > temp_container[j] )
						{
							temp = temp_container[i];
							temp_container[i] = temp_container[j];
							temp_container[j] = temp;
						}
					}
				}
				stop_watch.Stop();

				std::cout << r2tm::tab2 << temp_container << r2tm::linefeed;

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
				std::cout << r2tm::tab2 << temp_container << r2tm::linefeed2;

				int temp = 0;
				for( int i = 0; temp_container.size() - 1 > i; ++i )
				{
					for( int j = i + 1; temp_container.size() > j; ++j )
					{
						if( temp_container[i] > temp_container[j] )
						{
							temp = temp_container[i];
							temp_container[i] = temp_container[j];
							temp_container[j] = temp;

							std::cout << r2tm::tab2 << temp_container << r2tm::tab2 << " swap : " << temp_container[i] << " <> " << temp_container[j];
							LF();
						}
					}

					std::cout << r2tm::linefeed2;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Case2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Selection Sort : Case 2";
		};
	}
	r2tm::DoFunctionT Case2::GetDoFunction() const
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
				std::cout << r2tm::tab << "+ Case : find min and swap" << r2tm::linefeed2;

				auto temp_container = test_container;

				stop_watch.Start();
				int temp = 0;
				for( int i = 0, min_index = 0; temp_container.size() - 1 > i; ++i )
				{
					min_index = i;

					for( int j = i + 1; temp_container.size() > j; ++j )
					{
						if( temp_container[min_index] > temp_container[j] )
						{
							min_index = j;
						}
					}

					temp = temp_container[i];
					temp_container[i] = temp_container[min_index];
					temp_container[min_index] = temp;
				}
				stop_watch.Stop();

				std::cout << r2tm::tab2 << temp_container << r2tm::linefeed;

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
				std::cout << r2tm::tab2 << temp_container << r2tm::linefeed2;

				for( int i = 0, min_index = 0; temp_container.size() - 1 > i; ++i )
				{
					min_index = i;

					std::cout << r2tm::tab2 << "start" << r2tm::linefeed;
					std::cout << r2tm::tab2 << "min index : " << min_index << r2tm::linefeed2;

					for( int j = i + 1; temp_container.size() > j; ++j )
					{
						if( temp_container[min_index] > temp_container[j] )
						{
							min_index = j;

							std::cout << r2tm::tab2 << "min index : " << min_index << r2tm::linefeed;
						}
					}

					const auto temp = temp_container[i];
					temp_container[i] = temp_container[min_index];
					temp_container[min_index] = temp;

					//
					//
					//
					std::cout << r2tm::tab2 << temp_container << r2tm::tab2 << " swap : " << temp_container[i] << " <> " << temp_container[min_index];
					std::cout << r2tm::linefeed3;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}