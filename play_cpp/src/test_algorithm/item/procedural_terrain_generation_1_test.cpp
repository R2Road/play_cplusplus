#include "procedural_terrain_generation_1_test.h"

#include <conio.h>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "r2/r2_Grid.h"
#include "r2/r2_Random.h"

#include "test_algorithm/AlgorithmHelper.h"

namespace procedural_terrain_generation_1_test
{
	enum class eTerrainType
	{
		Normal,
		Wall,
	};

	int GetNeighborCount( const r2::Grid<eTerrainType>& grid, const int px, const int py, const int allowed_range )
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

				count += ( grid.Get( x, y ) == eTerrainType::Wall ? 1 : 0 );
			}
		}

		return count;
	}
	std::function<char( eTerrainType )> terrain_type_evaluator = []( eTerrainType t )
	{
		return eTerrainType::Wall == t ? '=' : ' ';
	};

	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "PROCEDURAL TERRAIN GENERATION : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			r2::Grid<eTerrainType> grid;
			grid.Reset( 40, 40 );

			LS();

			const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();

			{
				std::cout << r2tm::tab << "+ Make Seed : r2::Random::GetInt( 0, 99 ) >= 50 ? eTerrainType::Normal : eTerrainType::Wall" << r2tm::linefeed2;

				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetWidth() > x; ++x )
					{
						grid.Set( x, y, r2::Random::GetInt( 0, 99 ) >= 50 ? eTerrainType::Normal : eTerrainType::Wall );
					}
				}

				AlgorithmHelper::PrintGrid( grid, terrain_type_evaluator );
				LF();
			}

			LF();
			std::cout << "> Next Step";
			_getch();
			r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

			r2::Grid<int> grid2;
			grid2.Reset( 40, 40 );

			{
				std::cout << r2tm::tab << "+ Weights View" << r2tm::linefeed2;

				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetWidth() > x; ++x )
					{
						grid2.Set( x, y, GetNeighborCount( grid, x, y, 1 ) );
					}
				}

				AlgorithmHelper::PrintGrid( grid2 );
				LF();
			}

			LF();
			std::cout << "> Next Step";
			_getch();
			r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

			r2::Grid<eTerrainType> grid3;
			grid3.Reset( 40, 40 );

			{
				std::cout << r2tm::tab << "+ Terranin View : If [ 4 < Neighbor Wall ] : [ Wall ] else if [ 4 > Neighbor Wall ] : [ Normal ]" << r2tm::linefeed2;

				int neighbor_count = 0;
				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetWidth() > x; ++x )
					{
						neighbor_count = GetNeighborCount( grid, x, y, 1 );

						if( 4 < neighbor_count )
						{
							grid3.Set( x, y, eTerrainType::Wall );
						}
						else if( 4 > neighbor_count )
						{
							grid3.Set( x, y, eTerrainType::Normal );
						}
						//else if( 4 == neighbor_count ) {}
					}
				}

				AlgorithmHelper::PrintGrid( grid3, terrain_type_evaluator );
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Test_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "PROCEDURAL TERRAIN GENERATION : Test 1";
		};
	}
	r2tm::DoFunctionT Test_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			r2::Grid<eTerrainType> grid_seed;
			grid_seed.Reset( 40, 40 );
			r2::Grid<eTerrainType> grid_terrain;
			grid_terrain.Reset( 40, 40 );

			LS();

			const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();

			{
				std::cout << r2tm::tab << "+ Make Seed : r2::Random::GetInt( 0, 99 ) >= 50 ? eTerrainType::Normal : eTerrainType::Wall" << r2tm::linefeed2;

				for( int y = 0; grid_seed.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_seed.GetWidth() > x; ++x )
					{
						grid_seed.Set( x, y, r2::Random::GetInt( 0, 99 ) >= 50 ? eTerrainType::Normal : eTerrainType::Wall );
					}
				}

				AlgorithmHelper::PrintGrid( grid_seed, terrain_type_evaluator );
				LF();
			}

			LF();
			std::cout << "> Next Step";
			_getch();
			r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

			{
				std::cout << r2tm::tab << "+ Terranin View : If [ Wall ] : [ 3 < Neighbor Wall : Wall ] else [ Normal ]" << r2tm::linefeed2;

				for( int y = 0; grid_seed.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_seed.GetWidth() > x; ++x )
					{
						if( eTerrainType::Wall == grid_seed.Get( x, y ) )
						{
							if( 3 < GetNeighborCount( grid_seed, x, y, 1 ) )
							{
								grid_terrain.Set( x, y, eTerrainType::Wall );
							}
							else
							{
								grid_terrain.Set( x, y, eTerrainType::Normal );
							}
						}
					}
				}

				AlgorithmHelper::PrintGrid( grid_terrain, terrain_type_evaluator );
				LF();
			}

			LF();
			std::cout << "> Next Step";
			_getch();
			r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

			{
				std::cout << r2tm::tab << "+ Terranin View : If [ Normal ] : [ 4 < Neighbor Wall : Wall ] else [ Normal ]" << r2tm::linefeed2;

				for( int y = 0; grid_seed.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_seed.GetWidth() > x; ++x )
					{
						if( eTerrainType::Normal == grid_seed.Get( x, y ) )
						{
							if( 4 < GetNeighborCount( grid_seed, x, y, 1 ) )
							{
								grid_terrain.Set( x, y, eTerrainType::Wall );
							}
							else
							{
								grid_terrain.Set( x, y, eTerrainType::Normal );
							}
						}
					}
				}

				AlgorithmHelper::PrintGrid( grid_terrain, terrain_type_evaluator );
				LF();
			}

			LS();

			LF();
			std::cout << "> Next Step";
			_getch();
			
			for( int i = 0; 5 > i; ++i )
			{
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

				std::cout << r2tm::tab << "+ Repeat x " << i << r2tm::linefeed2;

				for( int y = 0; grid_terrain.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_terrain.GetWidth() > x; ++x )
					{
						if( eTerrainType::Wall == grid_terrain.Get( x, y ) )
						{
							if( 3 >= GetNeighborCount( grid_terrain, x, y, 1 ) )
							{
								grid_terrain.Set( x, y, eTerrainType::Normal );
							}
						}
						else //if( eTerrainType::Normal == grid_terrain.Get( x, y ) )
						{
							if( 4 < GetNeighborCount( grid_terrain, x, y, 1 ) )
							{
								grid_terrain.Set( x, y, eTerrainType::Wall );
							}
						}
					}
				}

				AlgorithmHelper::PrintGrid( grid_terrain, terrain_type_evaluator );
				LF();

				_getch();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}