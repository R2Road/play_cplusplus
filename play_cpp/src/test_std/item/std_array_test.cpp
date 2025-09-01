#include "std_array_test.h"

#include <array>

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

#pragma warning( disable : 4101 )

namespace std_array_test
{
	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::array : Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUT_SOURCE_READY;

			LS();

			{
				OUT_SUBJECT( "Declaration" );

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> test_array;
					OUT_SOURCE_END;
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> test_array{ { 1, 2, 3 } };
					OUT_SOURCE_END;
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> test_array = { 1, 2, 3 };
					OUT_SOURCE_END;
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array aa{ 1, 2, 3 };
					OUT_SOURCE_END;
					std::cout << r2tm::tab2 << "* Note : Since c++17" << r2tm::linefeed;
				}
			}

			LS();

			{
				OUT_SUBJECT( "struct" );

				LF();

				DECL_MAIN( struct S { int i = 0; int j = 0; } );

				LF();

				OUT_SOURCE_BEGIN;
				using A = std::array<S, 2u>;
				OUT_SOURCE_END;

				SS();

				{

					LF();

					OUT_SOURCE_BEGIN;
					const A a( { { { 1, 2 }, { 3, 4 } } } );
					OUT_SOURCE_END;

					LF();

					for( const auto& i : a )
					{
						std::cout << "   " << i.i << "   " << i.j;
					}
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					const A b = { { { 5, 6 }, { 7, 8 } } };
					OUT_SOURCE_END;

					LF();

					for( const auto& i : b )
					{
						std::cout << "   " << i.i << "   " << i.j;
					}
				}

				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Fill::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::array : Fill";
		};
	}
	r2tm::DoFunctionT Fill::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			auto printer = []( const std::array<int, 3u>& container )
			{
				std::cout << r2tm::tab3 << "- Print : ";
				for( const auto i : container )
				{
					std::cout << i << r2tm::tab;
				}
				LF();
			};

			LS();

			std::cout << r2tm::tab << "+ Variable" << r2tm::linefeed2;

			std::array<int, 3u> test_array{ { 1, 2, 3 } };
			std::cout << r2tm::tab2 << "std::array<int, 3u> test_array{ { 1, 2, 3 } };" << r2tm::linefeed3;

			{
				test_array.fill( 4 );

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "test_array.fill( 4 );" << r2tm::linefeed;

				printer( test_array );
			}
			
			std::cout << r2tm::linefeed2;

			{
				std::fill( test_array.begin(), test_array.end(), 5 );

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "std::fill( test_array.begin(), test_array.end(), 5 );" << r2tm::linefeed;

				printer( test_array );
			}

			std::cout << r2tm::linefeed2;

			{
				std::fill_n( test_array.begin(), 1, 6 );

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "std::fill_n( test_array.begin(), 1, 6 );" << r2tm::linefeed2;

				printer( test_array );
			}

			std::cout << r2tm::linefeed2;

			{
				//std::fill_n( test_array.begin(), 5, 7 );

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "std::fill_n( test_array.begin(), 5, 6 );" << r2tm::linefeed2;
				std::cout << r2tm::tab3 << "- Not Working" << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Copy::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::array : Copy";
		};
	}
	r2tm::DoFunctionT Copy::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			auto printer = []( const std::array<int, 3u>& container )
			{
				std::cout << r2tm::tab << "Print : ";
				for( const auto i : container )
				{
					std::cout << i << r2tm::tab;
				}
				LF();
			};

			LS();

			std::cout << "# Note : Macro가 쉼표를 인자의 구별자로 인식해서 std::array 선언에 Inspector 활용이 안된다." << r2tm::linefeed;
			std::cout << "# Note : 생성자에서 array를 복사해야 한다면 std::array 를 활용해도 괜찮을듯." << r2tm::linefeed;

			LS();

			using TestArrayT = std::array<int, 3u>;
			std::cout << "using TestArrayT = std::array<int, 3u>;" << r2tm::linefeed2;

			{
				DECL_MAIN( TestArrayT array_1 );
				PROC_MAIN( array_1.fill( 2 ) );

				LF();

				DECL_MAIN( TestArrayT array_2 );
				printer( array_2 );

				LF();

				PROC_MAIN( array_2 = array_1 );
				printer( array_2 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}