#include "procedural_terrain_generation_2_test.h"

#include <conio.h>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "r2/r2_Grid.h"
#include "r2/r2_Random.h"

#include "test_algorithm/AlgorithmHelper.h"

namespace procedural_terrain_generation_2_test
{
	enum class eTerrainType
	{
		Normal,
		Wall_Normal,
		Wall_Immortal,
	};

	struct Cell
	{
		eTerrainType type = eTerrainType::Normal;
		int weight = 0;
	};

	int GetNeighborCount( const r2::Grid<Cell>& grid, const int px, const int py, const int allowed_range )
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

				count += ( grid.Get( x, y ).type != eTerrainType::Normal ? 1 : 0 );
			}
		}

		return count;
	}
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

				count += ( grid.Get( x, y ) != eTerrainType::Normal ? 1 : 0 );
			}
		}

		return count;
	}
	std::function<char( Cell )> seed_evaluator = []( Cell c )
	{
		return ( 0 == c.weight ? '0' : char( 48 + c.weight ) );
	};
	std::function<char( eTerrainType )> terrain_type_evaluator = []( eTerrainType t )
	{
		return eTerrainType::Wall_Immortal == t ? '+' : ( eTerrainType::Wall_Normal == t ? '=' : ' ' );
	};
	
	
	
	r2cm::iItem::TitleFuncT Bone::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "PROCEDURAL TERRAIN GENERATION 2 : Bone";
		};
	}
	r2cm::iItem::DoFuncT Bone::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			r2::Grid<Cell> grid_seed;
			grid_seed.Reset( 40, 40 );
			r2::Grid<eTerrainType> grid_terrain;
			grid_terrain.Reset( 40, 40 );

			std::cout << r2cm::split;

			const auto pivot_point = r2cm::WindowUtility::GetCursorPoint();

			{
				std::cout << r2cm::tab << "+ Make Seed" << r2cm::linefeed2;

				for( int y = 0; grid_seed.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_seed.GetWidth() > x; ++x )
					{
						const auto weight = r2::Random::GetInt( 0, 99 );

						grid_seed.Set( x, y, weight >= 50
							? Cell{ eTerrainType::Normal, weight / 10 }
							: Cell{ eTerrainType::Wall_Normal, weight / 10 }
						);
					}
				}

				AlgorithmHelper::PrintGrid( grid_seed, seed_evaluator );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::linefeed;
			std::cout << "> Next Step";
			_getch();
			r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

			{
				std::cout << r2cm::tab << "+ Make Terranin [Immortal] : ( 9 <= grid_seed.Get( x, y ) && 80 <= r2::Random::GetInt( 0, 100 ) )" << r2cm::linefeed2;

				for( int y = 0; grid_seed.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_seed.GetWidth() > x; ++x )
					{
						const auto cell = grid_seed.Get( x, y );

						if( 8 <= cell.weight && 80 <= r2::Random::GetInt( 0, 100 ) )
						{
							grid_seed.Set( x, y, Cell{ eTerrainType::Wall_Immortal, cell.weight } );
							grid_terrain.Set( x, y, eTerrainType::Wall_Immortal );
						}
					}
				}

				AlgorithmHelper::PrintGrid( grid_terrain, terrain_type_evaluator );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::linefeed;
			std::cout << "> Next Step";
			_getch();
			r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

			{
				std::cout << r2cm::tab << "+ Terranin View : If [ Wall_Normal ] : [ 3 < Neighbor Wall : Wall_Normal ] else [ Normal ]" << r2cm::linefeed2;

				for( int y = 0; grid_seed.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_seed.GetWidth() > x; ++x )
					{
						if( eTerrainType::Wall_Normal == grid_seed.Get( x, y ).type )
						{
							if( 3 < GetNeighborCount( grid_seed, x, y, 1 ) )
							{
								grid_terrain.Set( x, y, eTerrainType::Wall_Normal );
							}
							else
							{
								grid_terrain.Set( x, y, eTerrainType::Normal );
							}
						}
					}
				}

				AlgorithmHelper::PrintGrid( grid_terrain, terrain_type_evaluator );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::linefeed;
			std::cout << "> Next Step";
			_getch();
			r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

			{
				std::cout << r2cm::tab << "+ Terranin View : If [ Normal ] : [ 4 < Neighbor Wall_Normal : Wall_Normal ] else [ Normal ]" << r2cm::linefeed2;

				for( int y = 0; grid_seed.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_seed.GetWidth() > x; ++x )
					{
						if( eTerrainType::Normal == grid_seed.Get( x, y ).type )
						{
							if( 4 < GetNeighborCount( grid_seed, x, y, 1 ) )
							{
								grid_terrain.Set( x, y, eTerrainType::Wall_Normal );
							}
							else
							{
								grid_terrain.Set( x, y, eTerrainType::Normal );
							}
						}
					}
				}

				AlgorithmHelper::PrintGrid( grid_terrain, terrain_type_evaluator );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::linefeed;
			std::cout << "> Next Step";
			_getch();
			
			for( int i = 0; 5 > i; ++i )
			{
				r2cm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );

				std::cout << r2cm::tab << "+ Repeat x " << i << r2cm::linefeed2;

				for( int y = 0; grid_terrain.GetHeight() > y; ++y )
				{
					for( int x = 0; grid_terrain.GetWidth() > x; ++x )
					{
						if( eTerrainType::Wall_Normal == grid_terrain.Get( x, y ) )
						{
							// Core : Suggest [3], 4
							if( 3 >= GetNeighborCount( grid_terrain, x, y, 1 ) )
							{
								grid_terrain.Set( x, y, eTerrainType::Normal );
							}
						}
						// �� �ڵ带 ���� �ص� ������ ���´�.
						else if( eTerrainType::Normal == grid_terrain.Get( x, y ) )
						{
							// Core : Suggest 4, [5]
							if( 5 < GetNeighborCount( grid_terrain, x, y, 1 ) )
							{
								grid_terrain.Set( x, y, eTerrainType::Wall_Normal );
							}
						}
					}
				}

				AlgorithmHelper::PrintGrid( grid_terrain, terrain_type_evaluator );
				std::cout << r2cm::linefeed;

				_getch();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}