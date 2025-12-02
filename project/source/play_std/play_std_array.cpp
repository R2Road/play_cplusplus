#include "play_std_array.hpp"

#include <array>

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

#pragma warning( disable : 4101 )

namespace play_std_array
{
	template<class T, size_t N>
	void PrintArray( const std::array<T, N>& arr )
	{
		for( const auto& i : arr )
		{
			std::cout << i << r2tm::tab;
		}
		LF();
	}

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
				OUT_SUBJECT( "기본" );

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> a;
					OUT_SOURCE_END;

					PrintArray( a );
				}
			}

			SS();

			{
				OUT_SUBJECT( "생성자" );

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> a{};
					OUT_SOURCE_END;

					PrintArray( a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> a{ {} };
					OUT_SOURCE_END;

					PrintArray( a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> a{ { 1, 2 } };
					OUT_SOURCE_END;

					PrintArray( a );
				}
			}

			SS();

			{
				OUT_SUBJECT( "=" );

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> a = {};
					OUT_SOURCE_END;

					PrintArray( a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					std::array<int, 3u> a = { 1, 2 };
					OUT_SOURCE_END;

					PrintArray( a );
				}
			}

			LS();

			{

				OUT_NOTE( "Since c++17" );

				LF();

				OUT_SOURCE_BEGIN;
				std::array a{ 1, 2 };
				OUT_SOURCE_END;

				PrintArray( a );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Declaration_Struct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::array : Declaration Struct";
		};
	}
	r2tm::DoFunctionT Declaration_Struct::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUT_SOURCE_READY;

			LS();

			OUT_SUBJECT( "std::array 에 struct 를 담았을 때의 초기화" );

			LS();

			OUT_SOURCE_BEGIN;
			struct S
			{
				int i = 0;
				int j = 0;
			};

			using A = std::array<S, 2u>;
			OUT_SOURCE_END;

			const auto L = []( const A& a )
			{
				for( const auto& i : a )
				{
					std::cout << "   " << i.i << "   " << i.j;
				}
				LF();
			};

			LS();

			{
				{
					OUT_SOURCE_BEGIN;
					const A a;
					OUT_SOURCE_END;

					L( a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					const A a( {} );
					OUT_SOURCE_END;

					L( a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					const A a( { {} } );
					OUT_SOURCE_END;

					L( a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					const A a( { { {}, {} } } );
					OUT_SOURCE_END;

					L( a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					const A a( { { { 1, 2 }, { 3, 4 } } } );
					OUT_SOURCE_END;

					L( a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					const A a = { { { 5, 6 }, { 7, 8 } } };
					OUT_SOURCE_END;

					L( a );
				}
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



	r2tm::TitleFunctionT Array_Within_Struct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::array : Array Within Struct";
		};
	}
	r2tm::DoFunctionT Array_Within_Struct::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUT_SOURCE_READY;

			LS();

			OUT_SUBJECT( "struct 멤버인 Array의 초기화" );

			LS();

			OUT_SOURCE_BEGIN;
			using A = std::array<int, 3u>;
			OUT_SOURCE_END;

			const auto L = []( const A& a )
			{
				for( const auto& i : a )
				{
					std::cout << "   " << i;
				}
				LF();
			};

			LS();

			{
				{
					OUT_SOURCE_BEGIN;
					struct S
					{
						std::array<int, 3u> a;
					} s;
					OUT_SOURCE_END;

					L( s.a );
				}

				LF();

				{
					OUT_SOURCE_BEGIN;
					struct S
					{
						S() : a()
						{}

						std::array<int, 3u> a;
					} s;
					OUT_SOURCE_END;

					L( s.a );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}