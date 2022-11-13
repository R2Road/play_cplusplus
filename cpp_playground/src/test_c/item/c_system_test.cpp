#include "c_system_test.h"

#include <stdlib.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_system_test
{
	r2cm::iItem::TitleFunctionT Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "system : Pause";
		};
	}
	r2cm::iItem::DoFunctionT Pause::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				PROCESS_MAIN( system( "pause" ) );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( printf( "test" ); );
				PROCESS_MAIN( system( "pause" ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}