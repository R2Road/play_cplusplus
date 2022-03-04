#include "pch.h"
#include "std_array_test.h"

#include <array>

#include "base/r2_eTestEndAction.h"

#pragma warning( disable : 4101 )

namespace std_array_test
{
	r2::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array : Declaration";
		};
	}
	r2::iItem::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;

			{
				std::array<int, 3u> test_array;
				std::cout << r2::tab2 << "std::array<int, 3u> test_array;" << r2::linefeed2;
			}

			{
				std::array<int, 3u> test_array{ { 1, 2, 3 } };
				std::cout << r2::tab2 << "std::array<int, 3u> test_array{ { 1, 2, 3 } };" << r2::linefeed2;
			}

			{
				std::array<int, 3u> test_array = { 1, 2, 3 };
				std::cout << r2::tab2 << "std::array<int, 3u> test_array = { 1, 2, 3 };" << r2::linefeed2;
			}

			{
				std::array aa{ 1, 2, 3 };
				std::cout << r2::tab2 << "std::array aa{ 1, 2, 3 };" << r2::linefeed;
				std::cout << r2::tab2 << "* Note : Since c++17" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}



	r2::iItem::TitleFuncT Fill::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array : Fill";
		};
	}
	r2::iItem::DoFunc Fill::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			auto printer = []( const std::array<int, 3u> container )
			{
				std::cout << r2::tab3 << "- Print : ";
				for( const auto i : container )
				{
					std::cout << i << r2::tab;
				}
				std::cout << r2::linefeed;
			};

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Variable" << r2::linefeed2;

			std::array<int, 3u> test_array{ { 1, 2, 3 } };
			std::cout << r2::tab2 << "std::array<int, 3u> test_array{ { 1, 2, 3 } };" << r2::linefeed3;

			{
				test_array.fill( 4 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "test_array.fill( 4 );" << r2::linefeed;

				printer( test_array );
			}
			
			std::cout << r2::linefeed2;

			{
				std::fill( test_array.begin(), test_array.end(), 5 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "std::fill( test_array.begin(), test_array.end(), 5 );" << r2::linefeed;

				printer( test_array );
			}

			std::cout << r2::linefeed2;

			{
				std::fill_n( test_array.begin(), 1, 6 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "std::fill_n( test_array.begin(), 1, 6 );" << r2::linefeed2;

				printer( test_array );
			}

			std::cout << r2::linefeed2;

			{
				//std::fill_n( test_array.begin(), 5, 7 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "std::fill_n( test_array.begin(), 5, 6 );" << r2::linefeed2;
				std::cout << r2::tab3 << "- Not Working" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}