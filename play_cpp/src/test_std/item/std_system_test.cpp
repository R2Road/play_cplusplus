#include "std_system_test.h"

#include <cstdlib>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_system_test
{
	r2tm::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::system : Demo";
		};
	}
	r2tm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				PROCESS_MAIN( std::system( "dir /w" ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}