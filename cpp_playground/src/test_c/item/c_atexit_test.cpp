#include "c_atexit_test.h"

#include <stdlib.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "r2/r2_Assert.h"

namespace c_atexit_test
{
	void test_atexit()
	{
		R2ASSERT( false, "test_atexit" );
	}

	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "atexit";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "프로그램이 종료될 때 등록한 함수가 작동된다." << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 0, atexit( test_atexit ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}