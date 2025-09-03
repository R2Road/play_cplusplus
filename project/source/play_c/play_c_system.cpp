#include "play_c_system.hpp"

#include <stdlib.h>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_c_system
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