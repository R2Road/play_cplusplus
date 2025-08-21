#include "c_operator_priority_test.h"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

#pragma warning( disable : 4127 )

namespace c_operator_priority_test
{
	void void_func() {}

	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator priority : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "더하기 보다 곱셈 먼저 작동" );

				LF();

				OUTPUT_VALUE( ( 2 * 1 + 1 ) );
				EXPECT_EQ( ( 2 * 1 + 1 ), ( ( 2 * 1 ) + 1 ) );
				EXPECT_NE( ( 2 * 1 + 1 ), ( 2 * ( 1 + 1 ) ) );

				LF();

				OUTPUT_VALUE( ( 1 + 1 * 2 ) );
				EXPECT_EQ( ( 1 + 1 * 2 ), ( 1 + ( 1 * 2 ) ) );
				EXPECT_NE( ( 1 + 1 * 2 ), ( ( 1 + 1 ) * 2 ) );
			}

			LS();

			{
				OUTPUT_NOTE( "우선 순위가 같은 연산자는 왼쪽 > 오른쪽" );

				LF();

				OUTPUT_VALUE( ( 2.f / 10.f * 2 ) );
				EXPECT_EQ( ( 2.f / 10.f * 2 ), ( ( 2.f / 10.f ) * 2 ) );
				EXPECT_NE( ( 2.f / 10.f * 2 ), ( 2.f / ( 10.f * 2 ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}