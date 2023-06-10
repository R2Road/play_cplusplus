#include "c_atexit_test.h"

#include <stdlib.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

#include "r2/r2_Assert.h"

namespace c_atexit_test
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

			OUTPUT_NOTE( "프로그램이 종료될 때 등록한 함수가 작동된다." );
			OUTPUT_NOTE( "반환값 : 성공 = 0, 실패 = 다른 값" );

			LS();

			{
				OUTPUT_NOTE( "Function" );

				LF();

				OUTPUT_FILE_RANGE( "src/test_c/item/c_atexit_test.cpp", 12, 15 );

				LF();

				EXPECT_EQ( 0, atexit( Do ) );
			}

			LS();

			{
				OUTPUT_NOTE( "Lambda" );

				LF();

				DECLARATION_MAIN( auto l = []() { R2ASSERT( false, "Lambda : test_atexit" ); } );

				EXPECT_EQ( 0, atexit( l ) );
			}

			LS();

			{
				OUTPUT_NOTE( "Static Method" );

				LF();

				DECLARATION_MAIN( struct S
				{
					static void Do()
					{
						R2ASSERT( false, "Static Method : test_atexit" );
					}
				} );

				EXPECT_EQ( 0, atexit( S::Do ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}