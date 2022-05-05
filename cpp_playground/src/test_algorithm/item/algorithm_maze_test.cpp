#include "pch.h"
#include "algorithm_maze_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <Windows.h>

#include "r2cm/r2cm_eTestEndAction.h"

#include "r2/r2_Direction4.h"
#include "r2/r2_Grid.h"
#include "r2/r2_PointInt.h"

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
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Maze : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			struct Cell
			{
				r2::Direction4 direction;
			};


			r2::Direction4 current_direction;
			r2::PointInt current_point{ 0, 0 };
			r2::PointInt temp_point{ 0, 0 };
			r2::Grid<int> grid;
			grid.Reset( 19, 19 );

			{
				grid.Set( current_point.GetX(), current_point.GetY(), true );

				int stay_count = 0;
				while( 4 >= stay_count )
				{
					temp_point.SetX( current_point.GetX() + current_direction.GetPoint().GetX() );
					temp_point.SetY( current_point.GetY() + current_direction.GetPoint().GetY() );

					if( !grid.IsIn( temp_point.GetX(), temp_point.GetY() ) ||  0 < grid.Get( temp_point.GetX(), temp_point.GetY() ) )
					{
						current_direction.Rotate( true );
						++stay_count;

						continue;
					}

					grid.Set( temp_point.GetX(), temp_point.GetY(), 1 );

					current_point = temp_point;
					stay_count = 0;

					ShowGrid( grid );

					//
					// Key
					//
					if( _kbhit() )
					{
						break;
					}
				}
			}

			return r2cm::eTestEndAction::Pause;
		};
	}
}