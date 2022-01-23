#include "pch.h"
#include "std_list_test.h"

#include <list>

#include "base/r2_eTestResult.h"

namespace std_list_test
{
	r2::iTest::TitleFunc Splice::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List : Splice";
		};
	}
	r2::iTest::DoFunc Splice::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			std::list<int> test_container_1 = { 1, 2, 3, 4, 5 };
			std::list<int> test_container_2 = { 10, 20, 30, 40, 50 };

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::list<int> test_container_1 = { 1, 2, 3, 4, 5 };" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_container_1 )
				{
					std::cout << i << " ";
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "std::list<int> test_container_2 = { 10, 20, 30, 40, 50 };" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_container_2 )
				{
					std::cout << i << " ";
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto target_itr = std::find( test_container_1.begin(), test_container_1.end(), 3 );
				test_container_2.splice( test_container_2.begin(), test_container_1, target_itr );

				std::cout << r2::tab << "+ Process" << r2::linefeed;
				std::cout << r2::tab2 << "auto target_itr = std::find( test_container_1.begin(), test_container_1.end(), 3 );" << r2::linefeed;
				std::cout << r2::tab2 << "test_container_2.splice( test_container_2.begin(), test_container_1, target_itr );" << r2::linefeed2;

				std::cout << r2::tab << "+ Result" << r2::linefeed;
				std::cout << r2::tab2 << "- test_container_1 : ";
				for( const auto i : test_container_1 )
				{
					std::cout << i << " ";
				}
				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "- test_container_2 : ";
				for( const auto i : test_container_2 )
				{
					std::cout << i << " ";
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto target_itr = std::find( test_container_1.begin(), test_container_1.end(), 4 );
				test_container_2.splice( test_container_2.begin(), test_container_1, target_itr, test_container_1.end() );

				std::cout << r2::tab << "+ Process" << r2::linefeed;
				std::cout << r2::tab2 << "auto target_itr = std::find( test_container_1.begin(), test_container_1.end(), 4 );" << r2::linefeed;
				std::cout << r2::tab2 << "test_container_2.splice( test_container_2.begin(), test_container_1, target_itr, test_container_1.end() );" << r2::linefeed2;

				std::cout << r2::tab << "+ Result" << r2::linefeed;
				std::cout << r2::tab2 << "- test_container_1 : ";
				for( const auto i : test_container_1 )
				{
					std::cout << i << " ";
				}
				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "- test_container_2 : ";
				for( const auto i : test_container_2 )
				{
					std::cout << i << " ";
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto target_itr = std::find( test_container_1.begin(), test_container_1.end(), 1 );
				auto end_itr = target_itr;
				++end_itr;
				test_container_2.splice( test_container_2.begin(), test_container_1, target_itr, end_itr );

				std::cout << r2::tab << "+ Process" << r2::linefeed;
				std::cout << r2::tab2 << "auto target_itr = std::find( test_container_1.begin(), test_container_1.end(), 1 );" << r2::linefeed;
				std::cout << r2::tab2 << "auto end_itr = target_itr;" << r2::linefeed;
				std::cout << r2::tab2 << "++end_itr;" << r2::linefeed;
				std::cout << r2::tab2 << "test_container_2.splice( test_container_2.begin(), test_container_1, target_itr, end_itr );" << r2::linefeed2;

				std::cout << r2::tab << "+ Result" << r2::linefeed;
				std::cout << r2::tab2 << "- test_container_1 : ";
				for( const auto i : test_container_1 )
				{
					std::cout << i << " ";
				}
				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "- test_container_2 : ";
				for( const auto i : test_container_2 )
				{
					std::cout << i << " ";
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}