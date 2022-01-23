#include "pch.h"
#include "algorithm_maze_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <Windows.h>

#include "base/r2_eTestResult.h"

#include "r2/r2_Direction4.h"
#include "r2/r2_Grid.h"
#include "r2/r2_Point.h"

namespace
{
	void ShowGrid( const r2::Grid<int>& grid )
	{
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

		std::cout << "# " << algorithm_maze_test::Basic::GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

		std::cout << "[ANY KEY] Exit" << r2::linefeed;

		std::cout << r2::split;

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

		std::cout << r2::linefeed;
		std::cout << r2::split;
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
			struct Cell
			{
				r2::Direction4 direction;
			};


			r2::Direction4 current_direction;
			r2::Point current_point{ 0, 0 };
			r2::Point temp_point{ 0, 0 };
			r2::Grid<int> grid;
			grid.Reset( 19, 19 );

			{
				grid.Set( current_point.x, current_point.y, true );

				bool process = true;
				int stay_count = 0;
				while( process && 4 >= stay_count )
				{
					temp_point.x = current_point.x + current_direction.GetPoint().x;
					temp_point.y = current_point.y + current_direction.GetPoint().y;

					if( !grid.IsIn( temp_point.x, temp_point.y ) ||  0 < grid.Get( temp_point.x, temp_point.y ) )
					{
						current_direction.Rotate( true );
						++stay_count;

						continue;
					}

					grid.Set( temp_point.x, temp_point.y, 1 );

					current_point = temp_point;
					stay_count = 0;

					ShowGrid( grid );

					//
					// Key
					//
					if( _kbhit() )
					{
						process = false;
					}
				}
			}

			return r2::eTestResult::RunTest;
		};
	}
}