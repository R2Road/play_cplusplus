#include "pch.h"
#include "algorithm_astar_test.h"

#include <Windows.h>

#include "base/r2_eTestResult.h"

#include "algorithm/r2algorithm_AStarPathBuilder.h"
#include "r2/r2_Grid.h"
#include "r2/r2_Point.h"
#include "util/r2util_StopWatch.h"

namespace
{
	const r2::Grid<int> WORLD_MAP( 19, 19, {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
		1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1,
		1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1,
		1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1,
		1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1,
		1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1,
		1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1,
		1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	} );

	void ShowGrid( const r2::Grid<int>& grid )
	{
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

		std::cout << "# " << algorithm_astar_test::Basic::GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

		std::cout << r2::split;

		int x = 0;
		for( const auto i : grid )
		{
			if( grid.GetWidth() <= x )
			{
				x = 0;
				std::cout << r2::linefeed;
			}

			if( 0 == i )
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << "@ ";
			}

			++x;
		}

		std::cout << r2::linefeed;
		std::cout << r2::split;
	}

	void ShowPath( const r2::Point entry_point, const r2::Point exit_point, const std::list<r2::Point>& path )
	{
		const COORD pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( p.x * 2 )
				, pivot_point.Y + static_cast<short>( p.y )
			} );

			std::cout << '*';
		}

		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( entry_point.x * 2 )
				, pivot_point.Y + static_cast<short>( entry_point.y )
		} );
		std::cout << '1';
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( exit_point.x * 2 )
				, pivot_point.Y + static_cast<short>( exit_point.y )
		} );
		std::cout << '2';

		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 27 } );
	}
}

namespace algorithm_astar_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			const r2::Point entry_point{ 2, 1 };
			const r2::Point exit_point{ 16, 17 };

			ShowGrid( WORLD_MAP );

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::list<r2::Point> result_path;

				stop_watch.Start();
				r2algorithm::AStarPathBuilder::Build( entry_point, exit_point, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( entry_point, exit_point, result_path );
			}
			stop_watch.PrintLog_All();
			std::cout << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc WithVector::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : with Vector";
		};
	}
	r2::iTest::DoFunc WithVector::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			const r2::Point entry_point{ 2, 1 };
			const r2::Point exit_point{ 16, 17 };

			ShowGrid( WORLD_MAP );

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::list<r2::Point> result_path;

				stop_watch.Start();
				r2algorithm::AStarPathBuilder::Build( entry_point, exit_point, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( entry_point, exit_point, result_path );
			}
			stop_watch.PrintLog_All();
			std::cout << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}