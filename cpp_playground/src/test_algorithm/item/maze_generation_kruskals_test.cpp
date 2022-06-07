#include "maze_generation_kruskals_test.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "r2/r2_Direction4.h"
#include "r2/r2_Grid.h"

namespace maze_generation_kruskals_test
{
	void PrintGrid( const r2::Grid<int>& grid )
	{
		const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();

		for( int y = 0; grid.GetHeight() > y; ++y )
		{
			for( int x = 0; grid.GetHeight() > x; ++x )
			{
				const r2cm::WindowUtility::CursorPoint my_pivot_point = {
					pivot_point.x + static_cast<short>( x * 3 ) + 1
					, pivot_point.y + static_cast<short>( y * 3 ) + 1
				};
				r2cm::WindowUtility::MoveCursorPoint( my_pivot_point );
				std::cout << '@';

				r2::Direction4 dir4;
				for( int i = 0; 4 > i; ++i, dir4.Rotate( true ) )
				{
					if( grid.Get( x, y ) & dir4.GetState() )
					{
						r2cm::WindowUtility::MoveCursorPoint( { my_pivot_point.x + static_cast<short>( dir4.GetPoint().GetX() ), my_pivot_point.y + static_cast<short>( dir4.GetPoint().GetY() ) } );
						std::cout << '+';
					}
				}
			}
		}
	}

	r2cm::iItem::TitleFuncT ViewTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Kruskals : ViewTest";
		};
	}
	r2cm::iItem::DoFuncT ViewTest::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			DECLARATION_MAIN( r2::Grid<int> grid( 2, 2, r2::Direction4::eState::None ) );
			PROCESS_MAIN( grid.Set( 1, 0, r2::Direction4::eState::Up | r2::Direction4::eState::Down ) );
			PROCESS_MAIN( grid.Set( 1, 1, r2::Direction4::eState::Left | r2::Direction4::eState::Right ) );
			PROCESS_MAIN( grid.Set( 0, 1, r2::Direction4::eState::Left | r2::Direction4::eState::Right | r2::Direction4::eState::Up ) );

			std::cout << r2cm::split;

			{
				PrintGrid( grid );
				std::cout << r2cm::linefeed2;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}