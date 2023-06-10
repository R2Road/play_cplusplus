#include "c_random_test.h"

#include <cstdlib> // rand, srand

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"


namespace c_random_test
{
	r2tm::TitleFunctionT Rand::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Rand : Basic";
		};
	}
	r2tm::DoFunctionT Rand::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				for( int i = 0; 5 > i; ++i )
				{
					OUTPUT_VALUE( rand() );
				}

				LF();

				OUTPUT_NOTE( "Same Value Printed When Every Single Execute" );
				OUTPUT_NOTE( "프로그램 새로 기동해도 rand() 가 반환하는 값과 순서는 같다." );
			}

			LS();

			{
				PROCESS_MAIN( srand( 1 ) );

				LF();

				for( int i = 0; 5 > i; ++i )
				{
					OUTPUT_VALUE( rand() );
				}

				LF();

				OUTPUT_NOTE( "srand( 1 ) is Default" );
				OUTPUT_NOTE( "srand( n ) is init rand() Sequence" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}