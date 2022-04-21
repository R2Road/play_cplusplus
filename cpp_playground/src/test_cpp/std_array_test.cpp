#include "pch.h"
#include "std_array_test.h"

#include <array>

#include "base/r2cm_eTestEndAction.h"
#include "r2/r2_Inspector.h"

#pragma warning( disable : 4101 )

namespace std_array_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array : Declaration";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Fill::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array : Fill";
		};
	}
	r2cm::iItem::DoFuncT Fill::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Copy::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array : Copy";
		};
	}
	r2cm::iItem::DoFuncT Copy::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			auto printer = []( const std::array<int, 3u>& container )
			{
				std::cout << r2::tab << "Print : ";
				for( const auto i : container )
				{
					std::cout << i << r2::tab;
				}
				std::cout << r2::linefeed;
			};

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << "# Note : Macro가 쉼표를 인자의 구별자로 인식해서 std::array 선언에 Inspector 활용이 안된다." << r2::linefeed;
			std::cout << "# Note : 생성자에서 array를 복사해야 한다면 std::array 를 활용해도 괜찮을듯." << r2::linefeed;

			std::cout << r2::split;

			using TestArrayT = std::array<int, 3u>;
			std::cout << "using TestArrayT = std::array<int, 3u>;" << r2::linefeed2;

			{
				DECLARATION_MAIN( TestArrayT array_1 );
				PROCESS_MAIN( array_1.fill( 2 ) );

				std::cout << r2::linefeed;

				DECLARATION_MAIN( TestArrayT array_2 );
				printer( array_2 );

				std::cout << r2::linefeed;

				PROCESS_MAIN( array_2 = array_1 );
				printer( array_2 );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}