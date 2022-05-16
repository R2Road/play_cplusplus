#include "std_array_test.h"

#include <array>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

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
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;

			{
				std::array<int, 3u> test_array;
				std::cout << r2cm::tab2 << "std::array<int, 3u> test_array;" << r2cm::linefeed2;
			}

			{
				std::array<int, 3u> test_array{ { 1, 2, 3 } };
				std::cout << r2cm::tab2 << "std::array<int, 3u> test_array{ { 1, 2, 3 } };" << r2cm::linefeed2;
			}

			{
				std::array<int, 3u> test_array = { 1, 2, 3 };
				std::cout << r2cm::tab2 << "std::array<int, 3u> test_array = { 1, 2, 3 };" << r2cm::linefeed2;
			}

			{
				std::array aa{ 1, 2, 3 };
				std::cout << r2cm::tab2 << "std::array aa{ 1, 2, 3 };" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "* Note : Since c++17" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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
		return []()->r2cm::eItemLeaveAction
		{
			auto printer = []( const std::array<int, 3u>& container )
			{
				std::cout << r2cm::tab3 << "- Print : ";
				for( const auto i : container )
				{
					std::cout << i << r2cm::tab;
				}
				std::cout << r2cm::linefeed;
			};

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed2;

			std::array<int, 3u> test_array{ { 1, 2, 3 } };
			std::cout << r2cm::tab2 << "std::array<int, 3u> test_array{ { 1, 2, 3 } };" << r2cm::linefeed3;

			{
				test_array.fill( 4 );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "test_array.fill( 4 );" << r2cm::linefeed;

				printer( test_array );
			}
			
			std::cout << r2cm::linefeed2;

			{
				std::fill( test_array.begin(), test_array.end(), 5 );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::fill( test_array.begin(), test_array.end(), 5 );" << r2cm::linefeed;

				printer( test_array );
			}

			std::cout << r2cm::linefeed2;

			{
				std::fill_n( test_array.begin(), 1, 6 );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::fill_n( test_array.begin(), 1, 6 );" << r2cm::linefeed2;

				printer( test_array );
			}

			std::cout << r2cm::linefeed2;

			{
				//std::fill_n( test_array.begin(), 5, 7 );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::fill_n( test_array.begin(), 5, 6 );" << r2cm::linefeed2;
				std::cout << r2cm::tab3 << "- Not Working" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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
		return []()->r2cm::eItemLeaveAction
		{
			auto printer = []( const std::array<int, 3u>& container )
			{
				std::cout << r2cm::tab << "Print : ";
				for( const auto i : container )
				{
					std::cout << i << r2cm::tab;
				}
				std::cout << r2cm::linefeed;
			};

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << "# Note : Macro가 쉼표를 인자의 구별자로 인식해서 std::array 선언에 Inspector 활용이 안된다." << r2cm::linefeed;
			std::cout << "# Note : 생성자에서 array를 복사해야 한다면 std::array 를 활용해도 괜찮을듯." << r2cm::linefeed;

			std::cout << r2cm::split;

			using TestArrayT = std::array<int, 3u>;
			std::cout << "using TestArrayT = std::array<int, 3u>;" << r2cm::linefeed2;

			{
				DECLARATION_MAIN( TestArrayT array_1 );
				PROCESS_MAIN( array_1.fill( 2 ) );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( TestArrayT array_2 );
				printer( array_2 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( array_2 = array_1 );
				printer( array_2 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}