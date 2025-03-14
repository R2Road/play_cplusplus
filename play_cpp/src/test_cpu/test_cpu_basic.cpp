#include "test_cpu_basic.h"

#include "r2tm/r2tm_ostream.h"

#include "r2tm/r2tm_StopWatch.h"

namespace test_cpu_basic
{
	r2tm::TitleFunctionT Test::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Test";
		};
	}
	r2tm::DoFunctionT Test::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}