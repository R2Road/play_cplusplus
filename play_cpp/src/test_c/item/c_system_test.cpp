#include "c_system_test.h"

#include <stdlib.h>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

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
			LS();

			{
				PROC_MAIN( system( "pause" ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}