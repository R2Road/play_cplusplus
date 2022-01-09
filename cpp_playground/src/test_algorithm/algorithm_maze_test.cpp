#include "pch.h"
#include "algorithm_maze_test.h"

#include "base/r2_eTestResult.h"

#include "r2/r2_Grid.h"

namespace
{
	void ShowGrid( const r2::Grid<int> grid )
	{
		int x = 0;
		for( const auto i : grid )
		{
			if( grid.GetWidth() <= x )
			{
				x = 0;
				std::cout << r2::linefeed;
			}

			std::cout << i;

			++x;
		}
	}
}

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

			r2::Grid<int> grid;
			grid.Reset( 19, 19 );

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;

			{
				ShowGrid( grid );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}