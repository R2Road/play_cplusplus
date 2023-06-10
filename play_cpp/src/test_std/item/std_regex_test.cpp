#include "std_regex_test.h"

#include "r2tm/r2tm_ostream.h"

namespace std_regex_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Regex : Basic( To do )";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}