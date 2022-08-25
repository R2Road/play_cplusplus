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
	r2cm::iItem::DoFunctionT Rand::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;

				for( int i = 0; 5 > i; ++i )
				{
					OUTPUT_VALUE( rand() );;
				}

				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab << "# Message : Same Value Printed When Every Single Execute" << r2cm::linefeed;
				std::cout << r2cm::tab << "# Message : 프로그램 새로 기동해도 rand() 가 반환하는 값과 순서는 같다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;

				PROCESS_MAIN( srand( 1 ) );

				std::cout << r2cm::linefeed;

				for( int i = 0; 5 > i; ++i )
				{
					OUTPUT_VALUE( rand() );;
				}

				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab << "# Message : srand( 1 ) is Default" << r2cm::linefeed;
				std::cout << r2cm::tab << "# Message : srand( n ) is init rand() Sequence" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}