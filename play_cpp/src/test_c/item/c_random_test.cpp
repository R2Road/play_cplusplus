#include "c_random_test.h"

#include <cstdlib> // rand, srand

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"


namespace c_random_test
{
	r2cm::iItem::TitleFunctionT Rand::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Rand : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Rand::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				for( int i = 0; 5 > i; ++i )
				{
					OUTPUT_VALUE( rand() );
				}

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "Same Value Printed When Every Single Execute" );
				OUTPUT_NOTE( "���α׷� ���� �⵿�ص� rand() �� ��ȯ�ϴ� ���� ������ ����." );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( srand( 1 ) );

				std::cout << r2cm::linefeed;

				for( int i = 0; 5 > i; ++i )
				{
					OUTPUT_VALUE( rand() );
				}

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "srand( 1 ) is Default" );
				OUTPUT_NOTE( "srand( n ) is init rand() Sequence" );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}