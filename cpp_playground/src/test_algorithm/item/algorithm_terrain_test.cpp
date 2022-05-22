#include "algorithm_terrain_test.h"

#include <conio.h>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

#include "r2/r2_Grid.h"
#include "r2/r2_Random.h"

#include "test_algorithm/AlgorithmHelper.h"

namespace algorithm_terrain_test
{
	int GetNeighborCount( const r2::Grid<bool>& grid, const int px, const int py, const int allowed_range )
	{
		int count = 0;

		for( int y = py - allowed_range, yend = py + allowed_range; yend >= y; ++y )
		{
			for( int x = px - allowed_range, xend = px + allowed_range; xend >= x; ++x )
			{
				if( px == x && py == y )
				{
					continue;
				}

				if( !grid.IsIn( x, y ) )
				{
					continue;
				}

				count += grid.Get( x, y ) ? 1 : 0;
			}
		}

		return count;
	}

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
						grid.Set( x, y, r2::Random::GetInt( 0, 100 ) > 40 );
					}
				}

				AlgorithmHelper::PrintGrid( grid );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;
			_getch();

			{
				DECLARATION_MAIN( r2::Grid<int> grid2 );
				PROCESS_MAIN( grid2.Reset( 19, 19 ) );
				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetWidth() > x; ++x )
					{
						grid2.Set( x, y, GetNeighborCount( grid, x, y, 1 ) );
					}
				}

				AlgorithmHelper::PrintGrid( grid2 );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;
			_getch();

			{
				DECLARATION_MAIN( r2::Grid<bool> grid3 );
				PROCESS_MAIN( grid3.Reset( 19, 19 ) );
				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetWidth() > x; ++x )
					{
						if( 4 < GetNeighborCount( grid, x, y, 1 ) )
						{
							grid3.Set( x, y, true );
						}
						else if( 4 > GetNeighborCount( grid, x, y, 1 ) )
						{
							grid3.Set( x, y, false );
						}
					}
				}

				AlgorithmHelper::PrintGrid( grid3 );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}