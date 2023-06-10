#include "c_system_test.h"

#include <stdlib.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_system_test
{
	r2tm::TitleFunctionT Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "system : Pause";
		};
	}
	r2tm::DoFunctionT Pause::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				PROCESS_MAIN( system( "pause" ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}