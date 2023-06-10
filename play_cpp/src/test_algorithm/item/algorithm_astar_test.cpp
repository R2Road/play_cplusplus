#include "algorithm_astar_test.h"

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "algorithm/r2algorithm_astar_Constant.h"
#include "algorithm/r2algorithm_astar_PathBuilder.h"

#include "r2/r2_Grid.h"
#include "r2/r2_Point.h"

#include "r2tm/r2tm_StopWatch.h"

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
				std::cout << r2tm::linefeed;
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
		const r2tm::WindowUtility::CursorPoint pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			r2tm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( p.GetX() * 2 )
				, pivot_point.y + static_cast<short>( p.GetY() )
			} );

			std::cout << '*';
		}

		r2tm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( entry_point.GetX() * 2 )
				, pivot_point.y + static_cast<short>( entry_point.GetY() )
		} );
		std::cout << '1';
		r2tm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( exit_point.GetX() * 2 )
				, pivot_point.y + static_cast<short>( exit_point.GetY() )
		} );
		std::cout << '2';
	}

	void ShowPath( const r2::PointInt entry_point, const r2::PointInt exit_point, const std::vector<r2::PointInt>& path )
	{
		const r2tm::WindowUtility::CursorPoint pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			r2tm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( p.GetX() * 2 )
				, pivot_point.y + static_cast<short>( p.GetY() )
				} );

			std::cout << '*';
		}

		r2tm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( entry_point.GetX() * 2 )
				, pivot_point.y + static_cast<short>( entry_point.GetY() )
			} );
		std::cout << '1';
		r2tm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( exit_point.GetX() * 2 )
				, pivot_point.y + static_cast<short>( exit_point.GetY() )
			} );
		std::cout << '2';
	}
}

namespace algorithm_astar_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2tm::linefeed;
			std::cout << r2tm::split;

			r2tm::StopWatch stop_watch;
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

			r2tm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2tm::linefeed;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Use_STDListSplice::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice";
		};
	}
	r2tm::DoFunctionT Use_STDListSplice::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2tm::linefeed;
			std::cout << r2tm::split;

			r2tm::StopWatch stop_watch;
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

			r2tm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2tm::linefeed;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Use_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice, std::vector Result Path";
		};
	}
	r2tm::DoFunctionT Use_STDListSplice_STDVectorResultPath::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2tm::linefeed;
			std::cout << r2tm::split;

			r2tm::StopWatch stop_watch;
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

			r2tm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2tm::linefeed;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice, Decrease Close List, std::vector Result Path";
		};
	}
	r2tm::DoFunctionT Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2tm::linefeed;
			std::cout << r2tm::split;

			r2tm::StopWatch stop_watch;
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

			r2tm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2tm::linefeed2;

			std::cout << "## Not Have Changed" << r2tm::linefeed2;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Use_CostMap_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Cost Map, std::list::splice, std::vector Result Path";
		};
	}
	r2tm::DoFunctionT Use_CostMap_STDListSplice_STDVectorResultPath::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2tm::linefeed;
			std::cout << r2tm::split;

			r2tm::StopWatch stop_watch;
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

			r2tm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2tm::linefeed;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Use_TinyCostMap_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Tiny Cost Map, std::list::splice, std::vector Result Path";
		};
	}
	r2tm::DoFunctionT Use_TinyCostMap_STDListSplice_STDVectorResultPath::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2tm::linefeed;
			std::cout << r2tm::split;

			r2tm::StopWatch stop_watch;
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

			r2tm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2tm::linefeed;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Array Based List, Tiny Cost Map, std::vector Result Path";
		};
	}
	r2tm::DoFunctionT Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2tm::linefeed;
			std::cout << r2tm::split;

			r2tm::StopWatch stop_watch;
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

			r2tm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2tm::linefeed;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PerformanceTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Performance Test";
		};
	}
	r2tm::DoFunctionT PerformanceTest::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			const int attempt_limit = 1000;

			{
				std::cout << r2tm::tab << "+ Attempt Limit : " << attempt_limit << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ AStarPathBuilder" << r2tm::linefeed2;

				r2tm::StopWatch stop_watch;

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
				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ AStarPathBuilder_Use_STDListSplice" << r2tm::linefeed2;

				r2tm::StopWatch stop_watch;

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
				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ AStarPathBuilder_Use_STDListSplice_STDVectorResultPath" << r2tm::linefeed2;

				r2tm::StopWatch stop_watch;

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
				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ AStarPathBuilder_Use_STDListSplice_DecreaseCloseList_STDVectorResultPath" << r2tm::linefeed2;

				r2tm::StopWatch stop_watch;

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
				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath" << r2tm::linefeed2;

				r2tm::StopWatch stop_watch;

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
				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath" << r2tm::linefeed2;

				r2tm::StopWatch stop_watch;

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
				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath" << r2tm::linefeed2;

				r2tm::StopWatch stop_watch;

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
				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}