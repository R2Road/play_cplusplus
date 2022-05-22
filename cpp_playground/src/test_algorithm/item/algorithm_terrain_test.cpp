#include "algorithm_terrain_test.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

#include "r2/r2_Grid.h"
#include "r2/r2_Random.h"

#include "test_algorithm/AlgorithmHelper.h"

namespace algorithm_terrain_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Terrain : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( r2::Grid<bool> grid );
			PROCESS_MAIN( grid.Reset( 19, 19 ) );

			std::cout << r2cm::split;

			{
				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetWidth() > x; ++x )
					{
						grid.Set( x, y, r2::Random::GetInt( 0, 100 ) > 70 );
					}
				}

				AlgorithmHelper::PrintGrid( grid );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}