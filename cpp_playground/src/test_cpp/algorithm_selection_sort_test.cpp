#include "pch.h"
#include "algorithm_selection_sort_test.h"

#include <array>

#include "base/r2_eTestResult.h"
#include "util/r2util_StopWatch.h"

template<class _Elem, class _Traits, class ContainerT>
std::basic_ostream<_Elem, _Traits>& operator << ( std::basic_ostream<_Elem, _Traits>& _Ostr, const ContainerT& container )
{
	for( const auto a : container )
	{
		_Ostr << a << r2::tab;
	}

	return ( _Ostr );
}

namespace algorithm_selection_sort_test
{
	r2::iTest::TitleFunc Case1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Selection Sort : Case 1";
		};
	}
	r2::iTest::DoFunc Case1::GetDoFunction()
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
				std::cout << r2::tab << "+ Case 1 : comparison and swap" << r2::linefeed2;

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

				std::cout << r2::tab2 << temp_container << r2::linefeed;

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
				std::cout << r2::tab2 << temp_container << r2::linefeed2;

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

							std::cout << r2::tab2 << temp_container << r2::tab2 << " swap : " << temp_container[i] << " <> " << temp_container[j];
							std::cout << r2::linefeed;
						}
					}

					std::cout << r2::linefeed2;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Case2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Selection Sort : Case 2";
		};
	}
	r2::iTest::DoFunc Case2::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			const std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::array<int, 5u> test_container{ 5, 4, 3, 2, 1 };" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Case : find min and swap" << r2::linefeed2;

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

				std::cout << r2::tab2 << temp_container << r2::linefeed;

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
				std::cout << r2::tab2 << temp_container << r2::linefeed2;

				for( int i = 0, min_index = 0; temp_container.size() - 1 > i; ++i )
				{
					min_index = i;

					std::cout << r2::tab2 << "start" << r2::linefeed;
					std::cout << r2::tab2 << "min index : " << min_index << r2::linefeed2;

					for( int j = i + 1; temp_container.size() > j; ++j )
					{
						if( temp_container[min_index] > temp_container[j] )
						{
							min_index = j;

							std::cout << r2::tab2 << "min index : " << min_index << r2::linefeed;
						}
					}

					const auto temp = temp_container[i];
					temp_container[i] = temp_container[min_index];
					temp_container[min_index] = temp;

					//
					//
					//
					std::cout << r2::tab2 << temp_container << r2::tab2 << " swap : " << temp_container[i] << " <> " << temp_container[min_index];
					std::cout << r2::linefeed3;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}