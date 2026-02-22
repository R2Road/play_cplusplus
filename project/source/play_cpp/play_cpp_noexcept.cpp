#include "play_cpp_noexcept.hpp"

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_cpp_noexcept
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "noexcept : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "생성자에 noexcept 가 사용되었는지 확인 해보자.");

			LS();

			{
				OUT_SUBJECT( "생성자에 noexcept 미사용" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S_except
				{
					S_except() {}
				};
				OUT_SOURCE_END;

				LF();

				EXPECT_FALSE( noexcept( S_except() ) );
			}

			LS();

			{
				OUT_SUBJECT( "생성자에 noexcept 사용" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S_noexcept
				{
					S_noexcept() noexcept
					{}
				};
				OUT_SOURCE_END;

				LF();

				EXPECT_TRUE( noexcept( S_noexcept() ) );
			}

			LS();

			{
				OUT_NOTE( "static_assert( noexcept( ... ) )" );
				OUT_NOTE( "...의 형태로 사용하는 것을 기대해 볼 수 있다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
