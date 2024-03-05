#include "algorithm_maze_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

#include "r2/r2_Direction4.h"
#include "r2/r2_Grid.h"
#include "r2/r2_PointInt.h"

#include "r2tm/r2tm_WindowUtility.h"
#include "test_algorithm/AlgorithmHelper.h"

namespace algorithm_maze_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Maze : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << "[ANY KEY] Exit" << r2tm::linefeed;

			LS();

			DECLARATION_MAIN( r2::Direction4 current_direction );
			DECLARATION_MAIN( r2::PointInt current_point( 0, 0 ) );
			DECLARATION_MAIN( r2::PointInt next_point( 0, 0 ) );
			DECLARATION_MAIN( r2::Grid<int> grid );

			LS();

			{
				PROCESS_MAIN( grid.Reset( 19, 19 ) );
				PROCESS_MAIN( grid.Set( current_point.GetX(), current_point.GetY(), true ) );

				LF();

				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
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
					r2tm::WindowUtility::MoveCursorPoint( pivot_point );
					AlgorithmHelper::PrintGrid( grid );
					LF();

					//
					// Key
					//
					if( _kbhit() )
					{
						break;
					}
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Test::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Maze : Test";
		};
	}
	r2tm::DoFunctionT Test::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << "[ANY KEY] Exit" << r2tm::linefeed;

			LS();

			DECLARATION_MAIN( r2::Direction4 current_direction );
			DECLARATION_MAIN( r2::PointInt current_point( 0, 0 ) );
			DECLARATION_MAIN( r2::PointInt next_point( 0, 0 ) );
			DECLARATION_MAIN( r2::Grid<int> grid );

			LS();

			{
				PROCESS_MAIN( grid.Reset( 19, 19 ) );

				PROCESS_MAIN( current_point.Set( static_cast<int>( grid.GetWidth() / 2 ), static_cast< int >( grid.GetHeight() / 2 ) ) );
				PROCESS_MAIN( grid.Set( current_point.GetX(), current_point.GetY(), 1 ) );

				LF();

				const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();
				int rotate_count = 0;
				int move_length = 1;
				int current_length = 1;
				do
				{

					next_point = current_point;
					next_point.Add( current_direction.GetPoint().GetX(), current_direction.GetPoint().GetY() );
					if( !grid.IsIn( next_point.GetX(), next_point.GetY() ) )
					{
						break;
					}

					grid.Set( next_point.GetX(), next_point.GetY(), 1 );

					current_point = next_point;

					++current_length;
					if( move_length <= current_length )
					{
						current_length = 0;

						current_direction.Rotate( true );
						++rotate_count;
						if( 2 <= rotate_count )
						{
							++move_length;
							rotate_count = 0;
						}
					}



					//
					// Output
					//
					r2tm::WindowUtility::MoveCursorPoint( pivot_point );
					AlgorithmHelper::PrintGrid( grid );
					LF();

					//
					// Key
					//
					if( _kbhit() )
					{
						break;
					}

				} while( true );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}