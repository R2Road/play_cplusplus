#include "c_atexit_test.h"

#include <stdlib.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

#include "r2/r2_Assert.h"

namespace c_atexit_test
{
	void Do()
	{
		R2ASSERT( false, "Function : test_atexit" );
	}

	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "atexit";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "���α׷��� ����� �� ����� �Լ��� �۵��ȴ�." );
			OUTPUT_NOTE( "��ȯ���� �����ϸ� 0, ������ �ƴϸ� �ٸ� ��" );

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Function" );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, atexit( Do ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Lambda" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto test_atexit = []() { R2ASSERT( false, "Lambda : test_atexit" ); } );

				EXPECT_EQ( 0, atexit( test_atexit ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Static Method" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( struct Test_AtExit
				{
					static void Do()
					{
						R2ASSERT( false, "Static Method : test_atexit" );
					}
				} );

				EXPECT_EQ( 0, atexit( Test_AtExit::Do ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}