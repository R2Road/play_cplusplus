#include "play_cpp_decltype.hpp"
#include "play_cpp_decltype_helper___template.hpp"

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_cpp_decltype
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "decltype : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "기본" );

				LF();

				DECL_MAIN( float f = 1.f );
				DECL_MAIN( decltype( f ) j = f );
				j = {}; // warning 제거
			}

			LS();

			{
				OUT_SUBJECT( "구조체 와 멤버 타입" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					float f = 1.f;
				} s;
				OUT_SOURCE_END;

				LF();

				DECL_MAIN( decltype( s ) s2 );
				DECL_MAIN( decltype( s.f ) sf );
				sf = {}; // warning 제거
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Function::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "decltype : Function";
		};
	}
	r2tm::DoFunctionT Function::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "함수 포인터" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					float get() const
					{
						return 1;
					}
				};
				OUT_SOURCE_END;

				LF();

				DECL_MAIN( decltype( &S::get ) p = &S::get );
				p = {}; // warning 제거
			}

			LS();

			{
				OUT_SUBJECT( "반환 타입 자동 설정" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					float get() const
					{
						return 1;
					}

					decltype( auto ) get2() const
					{
						return get();
					}

					auto get3() const
					{
						return get(); // 그냥 auto 를 쓰는게...
					}
				};
				OUT_SOURCE_END;
			}

			LS();

			{
				OUT_SUBJECT( "함수 인자" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					float get3( float a, decltype( a ) b ) const
					{
						return a + b;
					}
				};
				OUT_SOURCE_END;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Lambda::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "decltype : Lambda";
		};
	}
	r2tm::DoFunctionT Lambda::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "람다 인자" );
				OUT_COMMENT( "이 방식은 함수에서는 안된다." );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				auto l = []( int a ) -> decltype( a )
				{
					return a;
				};

				auto l2 = []( int a ) -> auto // 이 것 역시 auto를 쓰는게...
				{
					return a;
				};
				OUT_SOURCE_END;

				LF();

				PROC_MAIN( l( 1 ) );
				PROC_MAIN( l2( 1 ) );
			}

			LS();

			{
				OUT_SUBJECT( "operator의 반환 타입 끌어오기" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					float f = 1.f;

					double operator+( S a ) const
					{
						return (double)( a.f + f );
					}
				};

				auto l = []( S a, S b ) -> decltype( a + b )
				{
					return a + b;
				};

				auto l2 = []( S a, S b ) -> auto // 이 것 역시 auto를 쓰는게...
				{
					return a + b;
				};
				OUT_SOURCE_END;

				LF();

				PROC_MAIN( l( S(), S() ) );
				PROC_MAIN( l2( S(), S() ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}






	r2tm::TitleFunctionT Template::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "decltype : Template";
		};
	}
	r2tm::DoFunctionT Template::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "람다 와 템플릿" );

				LF();

				OUT_FILE( "source/play_cpp/play_cpp_decltype_helper___template.hpp" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					float f = 1.f;

					double operator+( S a ) const
					{
						return ( double )( a.f + f );
					}
				};
				OUT_SOURCE_END;

				LF();

				PROC_MAIN( lambda_func_1( S(), S() ) );
				PROC_MAIN( lambda_func_1( S(), S() ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
