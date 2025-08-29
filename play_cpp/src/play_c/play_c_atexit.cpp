#include "play_c_atexit.hpp"

#include <stdlib.h>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

#include "r2/r2_assert.hpp"

namespace play_c_atexit
{
	void Do()
	{
		R2ASSERT( false, "Function : test_atexit" );
	}

	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "atexit";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "프로그램이 종료될 때 등록한 함수가 작동된다." );
				OUTPUT_NOTE( "반환값 : 성공 = 0, 실패 = 다른 값" );

				LF();

				OUTPUT_NOTE( "늦게 추가한 함수가 먼저 작동한다. : Stack" );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Function" );

				LF();

				OUTPUT_FILE_RANGE( __FILE__, 12, 15 );

				LF();

				EXPECT_EQ( 0, atexit( Do ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Lambda" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto l = []()
				{
					R2ASSERT( false, "Lambda : test_atexit" );
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( 0, atexit( l ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Static Method" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					static void Do()
					{
						R2ASSERT( false, "Static Method : test_atexit" );
					}
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( 0, atexit( S::Do ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}