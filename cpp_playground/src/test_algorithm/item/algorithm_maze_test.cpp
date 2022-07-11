#include "algorithm_maze_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

#include "r2/r2_Direction4.h"
#include "r2/r2_Grid.h"
#include "r2/r2_PointInt.h"

#include "r2cm/r2cm_WindowUtility.h"
#include "test_algorithm/AlgorithmHelper.h"

namespace algorithm_maze_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Maze : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << algorithm_maze_test::Basic::GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << "[ANY KEY] Exit" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( r2::Direction4 current_direction );
			DECLARATION_MAIN( r2::PointInt current_point( 0, 0 ) );
			DECLARATION_MAIN( r2::PointInt next_point( 0, 0 ) );
			DECLARATION_MAIN( r2::Grid<int> grid );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( grid.Reset( 19, 19 ) );
				PROCESS_MAIN( grid.Set( current_point.GetX(), current_point.GetY(), true ) );

				std::cout << r2cm::linefeed;

				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();
				int stay_count = 0;
				while( 4 >= stay_count )
				{
					next_point = current_point + current_direction.GetPoint();

					if( !grid.IsIn( next_point.GetX(), next_point.GetY() ) ||  0 < grid.Get( next_point.GetX(), next_point.GetY() ) )
					{
						current_direction.Rotate( true );
						++stay_count;

						continue;
					}

					grid.Set( next_point.GetX(), next_point.GetY(), 1 );

					current_point = next_point;
					stay_count = 0;

					//
					// Output
					//
					r2cm::WindowUtility::MoveCursorPoint( pivot_point );
					AlgorithmHelper::PrintGrid( grid );
					std::cout << r2cm::linefeed;

					//
					// Key
					//
					if( _kbhit() )
					{
						break;
					}
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}