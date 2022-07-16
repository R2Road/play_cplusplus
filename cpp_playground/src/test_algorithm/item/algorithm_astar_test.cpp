#include "algorithm_astar_test.h"

#include "r2cm/r2cm_ostream.h"

#include "algorithm/r2algorithm_astar_Constant.h"
#include "algorithm/r2algorithm_astar_PathBuilder.h"

#include "r2/r2_Grid.h"
#include "r2/r2_Point.h"
#include "r2cm/r2cm_WindowUtility.h"

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
				std::cout << r2cm::linefeed;
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
		const r2cm::WindowUtility::CursorPoint pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			r2cm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( p.GetX() * 2 )
				, pivot_point.y + static_cast<short>( p.GetY() )
			} );

			std::cout << '*';
		}

		r2cm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( entry_point.GetX() * 2 )
				, pivot_point.y + static_cast<short>( entry_point.GetY() )
		} );
		std::cout << '1';
		r2cm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( exit_point.GetX() * 2 )
				, pivot_point.y + static_cast<short>( exit_point.GetY() )
		} );
		std::cout << '2';
	}

	void ShowPath( const r2::PointInt entry_point, const r2::PointInt exit_point, const std::vector<r2::PointInt>& path )
	{
		const r2cm::WindowUtility::CursorPoint pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			r2cm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( p.GetX() * 2 )
				, pivot_point.y + static_cast<short>( p.GetY() )
				} );

			std::cout << '*';
		}

		r2cm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( entry_point.GetX() * 2 )
				, pivot_point.y + static_cast<short>( entry_point.GetY() )
			} );
		std::cout << '1';
		r2cm::WindowUtility::MoveCursorPoint( {
				pivot_point.x + static_cast<short>( exit_point.GetX() * 2 )
				, pivot_point.y + static_cast<short>( exit_point.GetY() )
			} );
		std::cout << '2';
	}
}

namespace algorithm_astar_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2cm::linefeed;
			std::cout << r2cm::split;

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

			r2cm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2cm::linefeed;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Use_STDListSplice::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice";
		};
	}
	r2cm::iItem::DoFunctionT Use_STDListSplice::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2cm::linefeed;
			std::cout << r2cm::split;

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

			r2cm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2cm::linefeed;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Use_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFunctionT Use_STDListSplice_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2cm::linefeed;
			std::cout << r2cm::split;

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

			r2cm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2cm::linefeed;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice, Decrease Close List, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFunctionT Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2cm::linefeed;
			std::cout << r2cm::split;

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

			r2cm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2cm::linefeed2;

			std::cout << "## Not Have Changed" << r2cm::linefeed2;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Use_CostMap_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Cost Map, std::list::splice, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFunctionT Use_CostMap_STDListSplice_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2cm::linefeed;
			std::cout << r2cm::split;

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

			r2cm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2cm::linefeed;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Use_TinyCostMap_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Tiny Cost Map, std::list::splice, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFunctionT Use_TinyCostMap_STDListSplice_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2cm::linefeed;
			std::cout << r2cm::split;

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

			r2cm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2cm::linefeed;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Array Based List, Tiny Cost Map, std::vector Result Path";
		};
	}
	r2cm::iItem::DoFunctionT Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2cm::linefeed;
			std::cout << r2cm::split;

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

			r2cm::WindowUtility::MoveCursorPoint( { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2cm::linefeed;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PerformanceTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Performance Test";
		};
	}
	r2cm::iItem::DoFunctionT PerformanceTest::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			const int attempt_limit = 1000;

			{
				std::cout << r2cm::tab << "+ Attempt Limit : " << attempt_limit << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ AStarPathBuilder" << r2cm::linefeed2;

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
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ AStarPathBuilder_Use_STDListSplice" << r2cm::linefeed2;

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
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ AStarPathBuilder_Use_STDListSplice_STDVectorResultPath" << r2cm::linefeed2;

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
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ AStarPathBuilder_Use_STDListSplice_DecreaseCloseList_STDVectorResultPath" << r2cm::linefeed2;

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
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath" << r2cm::linefeed2;

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
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath" << r2cm::linefeed2;

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
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath" << r2cm::linefeed2;

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
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}