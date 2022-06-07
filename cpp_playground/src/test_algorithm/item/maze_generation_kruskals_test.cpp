#include "maze_generation_kruskals_test.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "r2/r2_Direction4.h"
#include "r2/r2_Grid.h"

namespace maze_generation_kruskals_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Kruskals : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			r2::Grid<int> grid;
			grid.Reset( 5, 5, r2::Direction4::eState::ALL );

			std::cout << r2cm::split;

			{
				const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();

				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetHeight() > x; ++x )
					{
						r2cm::WindowUtility::MoveCursorPoint( { pivot_point.x + static_cast<short>( x * 3 ), pivot_point.y + static_cast<short>( y * 3 ) } );
						std::cout << x;
					}
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}