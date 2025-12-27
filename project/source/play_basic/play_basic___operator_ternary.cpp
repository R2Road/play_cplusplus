#include "play_basic___operator_ternary.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_basic___operator_ternary
{
	void void_func() {}

	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_NOTE( "반환값이 없어도 된다." );

				LF();

				PROC_MAIN( ( true ? void_func() : void_func() ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Comma::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Comma";
		};
	}
	r2tm::DoFunctionT Comma::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_NOTE( "삼항 연산자의 실행식은 쉼표로 구분해 여러개 넣을 수 있다." );
			OUT_NOTE( "이걸 20년 만에 알았네. 2022.05.18" );

			LS();

			{
				DECL_MAIN( int i = 0 );
				DECL_MAIN( int j = 0 );

				LF();

				PROC_MAIN( (
					false
					? ++i, ++j
					: ++i
				) );

				LF();

				OUT_VALUE( i );
				OUT_VALUE( j );

				LF();

				PROC_MAIN( (
					true
					? ++i, ++j
					: ++i
				) );

				LF();

				OUT_VALUE( i );
				OUT_VALUE( j );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Void::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Void";
		};
	}
	r2tm::DoFunctionT Void::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_NOTE( "삼항 연산자에서 반환값 없는 함수를 호출하는 경우 void() 를 넣을 수 있다." );

			LS();

			{
				DECL_MAIN( std::function<void()> Do = []() {} );

				LF();

				PROC_MAIN( 1 == 1 ? Do() : void() );
				PROC_MAIN( 1 == 2 ? Do() : void() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}