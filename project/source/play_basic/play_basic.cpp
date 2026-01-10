#include "play_basic.hpp"

#include "r2tm/r2tm_color_modifier.hpp"
#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_basic
{
	r2tm::TitleFunctionT Primitive_Type_Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Primitive Type Size";
		};
	}
	r2tm::DoFunctionT Primitive_Type_Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "기본 제공 타입들의 크기" );

			LS();

			{
				OUT_SIZE( bool );
			}

			SS();

			{
				OUT_SIZE( char );
			}
			
			SS();

			{
				OUT_SIZE( short );

				LF();

				OUT_SIZE( int );

				LF();

				OUT_SIZE( long long );
			}

			SS();

			{
				OUT_SIZE( float );

				LF();

				OUT_SIZE( double );

				LF();

				OUT_SIZE( long double );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Pointer_Type_Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Pointer Type Size";
		};
	}
	r2tm::DoFunctionT Pointer_Type_Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "기본 제공 타입" );

				LF();

				OUT_SIZE( short* );

				LF();

				OUT_SIZE( long double* );
			}

			LS();

			{
				OUT_SUBJECT( "struct/class" );

				LF();

				DECL_MAIN( struct S {} s );

				LF();

				OUT_SIZE( &s );
			}

			LS();

			{
				OUT_SUBJECT( "함수" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					static void Func() {}
				};
				OUT_SOURCE_END;

				LF();

				OUT_SIZE( &S::Func );
			}

			LS();

			{
				OUT_SUBJECT( "일반 멤버 함수" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					void Func() {}
				} s;
				OUT_SOURCE_END;

				LF();

				OUT_SIZE( &S::Func );
			}

			LS();

			{
				OUT_SUBJECT( "가상 멤버 함수" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct B
				{
					virtual void Func() = 0;
				};
				struct S : public B
				{
					void Func() override {}
				} s;
				OUT_SOURCE_END;

				LF();

				OUT_SIZE( &S::Func );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}