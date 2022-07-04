#include "algorithm_selection_sort_test.h"

#include <array>

#include "r2cm/r2cm_constant.h"
#include "utility/r2utility_StopWatch.h"

template<class _Elem, class _Traits, class ContainerT>
std::basic_ostream<_Elem, _Traits>& operator << ( std::basic_ostream<_Elem, _Traits>& _Ostr, const ContainerT& container )
{
	for( const auto a : container )
	{
		_Ostr << a << r2cm::tab;
	}

	return ( _Ostr );
}

namespace algorithm_selection_sort_test
{
	r2cm::iItem::TitleFunctionT Case1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Selection Sort : Case 1";
		};
	}
	r2cm::iItem::DoFunctionT Case1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			r2utility::StopWatch stop_watch;
			const std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Case 1 : comparison and swap" << r2cm::linefeed2;

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

				std::cout << r2cm::tab2 << temp_container << r2cm::linefeed;

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
				std::cout << r2cm::tab2 << temp_container << r2cm::linefeed2;

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

							std::cout << r2cm::tab2 << temp_container << r2cm::tab2 << " swap : " << temp_container[i] << " <> " << temp_container[j];
							std::cout << r2cm::linefeed;
						}
					}

					std::cout << r2cm::linefeed2;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Case2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Selection Sort : Case 2";
		};
	}
	r2cm::iItem::DoFunctionT Case2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			r2utility::StopWatch stop_watch;
			const std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Case : find min and swap" << r2cm::linefeed2;

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

				std::cout << r2cm::tab2 << temp_container << r2cm::linefeed;

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
				std::cout << r2cm::tab2 << temp_container << r2cm::linefeed2;

				for( int i = 0, min_index = 0; temp_container.size() - 1 > i; ++i )
				{
					min_index = i;

					std::cout << r2cm::tab2 << "start" << r2cm::linefeed;
					std::cout << r2cm::tab2 << "min index : " << min_index << r2cm::linefeed2;

					for( int j = i + 1; temp_container.size() > j; ++j )
					{
						if( temp_container[min_index] > temp_container[j] )
						{
							min_index = j;

							std::cout << r2cm::tab2 << "min index : " << min_index << r2cm::linefeed;
						}
					}

					const auto temp = temp_container[i];
					temp_container[i] = temp_container[min_index];
					temp_container[min_index] = temp;

					//
					//
					//
					std::cout << r2cm::tab2 << temp_container << r2cm::tab2 << " swap : " << temp_container[i] << " <> " << temp_container[min_index];
					std::cout << r2cm::linefeed3;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}