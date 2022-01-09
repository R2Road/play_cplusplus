#include "pch.h"
#include "algorithm_maze_test.h"

#include "base/r2_eTestResult.h"

namespace algorithm_maze_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Maze : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}