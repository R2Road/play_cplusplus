#include "pch.h"
#include "algorithm_astar_test.h"

#include <Windows.h>

#include "base/r2cm_eTestEndAction.h"

#include "algorithm/r2algorithm_astar_Constant.h"
#include "algorithm/r2algorithm_astar_PathBuilder.h"
#include "r2/r2_Grid.h"
#include "r2/r2_Point.h"
#include "utility/r2utility_StopWatch.h"

using namespace r2algorithm_astar;

namespace
{
	void ShowGrid( const WorldMapT& grid )
	{
		int x = 0;
		for( const auto i : grid )
		{
			if( grid.GetWidth() <= x )
			{
				x = 0;
				std::cout << r2::linefeed;
			}

			if( 0 == i )
			{
				std::cout << "  ";
			}
			else
			{
				std::cout << "@ ";
			}

			++x;
		}
	}

	void ShowPath( const r2::PointInt entry_point, const r2::PointInt exit_point, const std::list<r2::PointInt>& path )
	{
		const COORD pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( p.GetX() * 2 )
				, pivot_point.Y + static_cast<short>( p.GetY() )
			} );

			std::cout << '*';
		}

		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( entry_point.GetX() * 2 )
				, pivot_point.Y + static_cast<short>( entry_point.GetY() )
		} );
		std::cout << '1';
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( exit_point.GetX() * 2 )
				, pivot_point.Y + static_cast<short>( exit_point.GetY() )
		} );
		std::cout << '2';
	}

	void ShowPath( const r2::PointInt entry_point, const r2::PointInt exit_point, const std::vector<r2::PointInt>& path )
	{
		const COORD pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( p.GetX() * 2 )
				, pivot_point.Y + static_cast<short>( p.GetY() )
				} );

			std::cout << '*';
		}

		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( entry_point.GetX() * 2 )
				, pivot_point.Y + static_cast<short>( entry_point.GetY() )
			} );
		std::cout << '1';
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( exit_point.GetX() * 2 )
				, pivot_point.Y + static_cast<short>( exit_point.GetY() )
			} );
		std::cout << '2';
	}
}

namespace algorithm_astar_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2utility::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::list<r2::PointInt> result_path;

				stop_watch.Start();
				r2algorithm_astar::AStarPathBuilder::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Use_STDListSplice::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice";
		};
	}
	r2cm::iItem::DoFuncT Use_STDListSplice::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2utility::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::list<r2::PointInt> result_path;

				stop_watch.Start();
				r2algorithm_astar::AStarPathBuilder_Use_STDListSplice::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Use_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFuncT Use_STDListSplice_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2utility::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				stop_watch.Start();
				r2algorithm_astar::AStarPathBuilder_Use_STDListSplice_STDVectorResultPath::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice, Decrease Close List, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFuncT Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2utility::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				stop_watch.Start();
				r2algorithm_astar::AStarPathBuilder_Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed2;

			std::cout << "## Not Have Changed" << r2::linefeed2;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Use_CostMap_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Cost Map, std::list::splice, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFuncT Use_CostMap_STDListSplice_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2utility::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm_astar::AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

				stop_watch.Start();
				builder.Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Use_TinyCostMap_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Tiny Cost Map, std::list::splice, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFuncT Use_TinyCostMap_STDListSplice_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2utility::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm_astar::AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

				stop_watch.Start();
				builder.Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Array Based List, Tiny Cost Map, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFuncT Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2utility::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm_astar::AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

				stop_watch.Start();
				builder.Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT PerformanceTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Performance Test";
		};
	}
	r2cm::iItem::DoFuncT PerformanceTest::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			const int attempt_limit = 1000;

			{
				std::cout << r2::tab << "+ Attempt Limit : " << attempt_limit << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ AStarPathBuilder" << r2::linefeed2;

				r2utility::StopWatch stop_watch;

				//
				// Build
				//
				for( int i = 0; attempt_limit > i; ++i )
				{
					std::list<r2::PointInt> result_path;

					stop_watch.Start();
					r2algorithm_astar::AStarPathBuilder::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
					stop_watch.Stop();
				}

				//
				// Show Time
				//
				stop_watch.PrintMinAndMaxTime();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ AStarPathBuilder_Use_STDListSplice" << r2::linefeed2;

				r2utility::StopWatch stop_watch;

				//
				// Build
				//
				for( int i = 0; attempt_limit > i; ++i )
				{
					std::list<r2::PointInt> result_path;

					stop_watch.Start();
					r2algorithm_astar::AStarPathBuilder_Use_STDListSplice::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
					stop_watch.Stop();
				}

				//
				// Show Time
				//
				stop_watch.PrintMinAndMaxTime();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ AStarPathBuilder_Use_STDListSplice_STDVectorResultPath" << r2::linefeed2;

				r2utility::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				for( int i = 0; attempt_limit > i; ++i )
				{
					stop_watch.Start();
					r2algorithm_astar::AStarPathBuilder_Use_STDListSplice_STDVectorResultPath::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
					stop_watch.Stop();
				}

				//
				// Show Time
				//
				stop_watch.PrintMinAndMaxTime();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ AStarPathBuilder_Use_STDListSplice_DecreaseCloseList_STDVectorResultPath" << r2::linefeed2;

				r2utility::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				for( int i = 0; attempt_limit > i; ++i )
				{
					stop_watch.Start();
					r2algorithm_astar::AStarPathBuilder_Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
					stop_watch.Stop();
				}

				//
				// Show Time
				//
				stop_watch.PrintMinAndMaxTime();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath" << r2::linefeed2;

				r2utility::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm_astar::AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

				for( int i = 0; attempt_limit > i; ++i )
				{
					stop_watch.Start();
					builder.Clear();
					builder.Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
					stop_watch.Stop();
				}

				//
				// Show Time
				//
				stop_watch.PrintMinAndMaxTime();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath" << r2::linefeed2;

				r2utility::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm_astar::AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

				for( int i = 0; attempt_limit > i; ++i )
				{
					stop_watch.Start();
					builder.Clear();
					builder.Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
					stop_watch.Stop();
				}

				//
				// Show Time
				//
				stop_watch.PrintMinAndMaxTime();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath" << r2::linefeed2;

				r2utility::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::PointInt> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm_astar::AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

				for( int i = 0; attempt_limit > i; ++i )
				{
					stop_watch.Start();
					builder.Clear();
					builder.Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
					stop_watch.Stop();
				}

				//
				// Show Time
				//
				stop_watch.PrintMinAndMaxTime();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}