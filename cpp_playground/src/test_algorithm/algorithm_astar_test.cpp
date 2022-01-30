#include "pch.h"
#include "algorithm_astar_test.h"

#include <Windows.h>

#include "base/r2_eTestResult.h"

#include "algorithm/r2algorithm_AStarPathBuilder.h"
#include "r2/r2_Grid.h"
#include "r2/r2_Point.h"
#include "util/r2util_StopWatch.h"

namespace
{
	const r2::Point ENTRY_POINT{ 2, 1 };
	const r2::Point EXIT_POINT{ 16, 17 };

	const r2::Grid<int> WORLD_MAP( 19, 19, {
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
		1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1,
		1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1,
		1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1,
		1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1,
		1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1,
		1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1,
		1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1,
		1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1,
		1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1,
		1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	} );

	void ShowGrid( const r2::Grid<int>& grid )
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

	void ShowPath( const r2::Point entry_point, const r2::Point exit_point, const std::list<r2::Point>& path )
	{
		const COORD pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( p.x * 2 )
				, pivot_point.Y + static_cast<short>( p.y )
			} );

			std::cout << '*';
		}

		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( entry_point.x * 2 )
				, pivot_point.Y + static_cast<short>( entry_point.y )
		} );
		std::cout << '1';
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( exit_point.x * 2 )
				, pivot_point.Y + static_cast<short>( exit_point.y )
		} );
		std::cout << '2';
	}

	void ShowPath( const r2::Point entry_point, const r2::Point exit_point, const std::vector<r2::Point>& path )
	{
		const COORD pivot_point{ 0, 4 };

		for( const auto p : path )
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( p.x * 2 )
				, pivot_point.Y + static_cast<short>( p.y )
				} );

			std::cout << '*';
		}

		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( entry_point.x * 2 )
				, pivot_point.Y + static_cast<short>( entry_point.y )
			} );
		std::cout << '1';
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), {
				pivot_point.X + static_cast<short>( exit_point.x * 2 )
				, pivot_point.Y + static_cast<short>( exit_point.y )
			} );
		std::cout << '2';
	}
}

namespace algorithm_astar_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::list<r2::Point> result_path;

				stop_watch.Start();
				r2algorithm::AStarPathBuilder::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Use_STDListSplice::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice";
		};
	}
	r2::iTest::DoFunc Use_STDListSplice::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::list<r2::Point> result_path;

				stop_watch.Start();
				r2algorithm::AStarPathBuilder_Use_STDListSplice::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Use_STDListSplice_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice, std::vector Result Path";
		};
	}
	r2::iTest::DoFunc Use_STDListSplice_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				stop_watch.Start();
				r2algorithm::AStarPathBuilder_Use_STDListSplice_STDVectorResultPath::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
				stop_watch.Stop();

				//
				// Show Path
				//
				ShowPath( ENTRY_POINT, EXIT_POINT, result_path );
			}

			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 26 } );
			stop_watch.PrintElapsedTime_All();
			std::cout << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc UseSTDListSplice_And_STDVectorResultPath_DecreaseCloseList::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use std::list::splice and std::vector Result Path and Decrease Close List";
		};
	}
	r2::iTest::DoFunc UseSTDListSplice_And_STDVectorResultPath_DecreaseCloseList::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				stop_watch.Start();
				r2algorithm::AStarPathBuilder_UseSTDListSplice_UseSTDVectorResultPath_DecreaseCloseList::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
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

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc UseCostMap::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Cost Map";
		};
	}
	r2::iTest::DoFunc UseCostMap::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm::AStarPathBuilder_UseCostMap_TinyData builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

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

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc UseCostMap_And_TinyData::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Cost Map and Tiny Data";
		};
	}
	r2::iTest::DoFunc UseCostMap_And_TinyData::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm::AStarPathBuilder_UseCostMap_TinyData builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

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

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Use_ArrayBasedList_CostMap_STDVectorResultPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : use Array Based List, CostMap, STDVector ResultPath";
		};
	}
	r2::iTest::DoFunc Use_ArrayBasedList_CostMap_STDVectorResultPath::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 0 } );

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			ShowGrid( WORLD_MAP );

			std::cout << r2::linefeed;
			std::cout << r2::split;

			r2util::StopWatch stop_watch;
			{
				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm::AStarPathBuilder_Use_ArrayBasedList_CostMap_STDVectorResultPath builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

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

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc PerformanceTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "A Star : Performance Test";
		};
	}
	r2::iTest::DoFunc PerformanceTest::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			const int attempt_limit = 1000;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "const int attempt_limit = " << attempt_limit << ";" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ AStarPathBuilder" << r2::linefeed2;

				r2util::StopWatch stop_watch;

				//
				// Build
				//
				for( int i = 0; attempt_limit > i; ++i )
				{
					std::list<r2::Point> result_path;

					stop_watch.Start();
					r2algorithm::AStarPathBuilder::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
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

				r2util::StopWatch stop_watch;

				//
				// Build
				//
				for( int i = 0; attempt_limit > i; ++i )
				{
					std::list<r2::Point> result_path;

					stop_watch.Start();
					r2algorithm::AStarPathBuilder_Use_STDListSplice::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
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

				r2util::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				for( int i = 0; attempt_limit > i; ++i )
				{
					stop_watch.Start();
					r2algorithm::AStarPathBuilder_Use_STDListSplice_STDVectorResultPath::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
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
				std::cout << r2::tab << "+ AStarPathBuilder_UseSTDListSplice_UseSTDVectorResultPath_DecreaseCloseList" << r2::linefeed2;

				r2util::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				for( int i = 0; attempt_limit > i; ++i )
				{
					stop_watch.Start();
					r2algorithm::AStarPathBuilder_UseSTDListSplice_UseSTDVectorResultPath_DecreaseCloseList::Build( ENTRY_POINT, EXIT_POINT, WORLD_MAP, &result_path );
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
				std::cout << r2::tab << "+ AStarPathBuilder_UseCostMap" << r2::linefeed2;

				r2util::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm::AStarPathBuilder_UseCostMap builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

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
				std::cout << r2::tab << "+ AStarPathBuilder_UseCostMap_TinyData" << r2::linefeed2;

				r2util::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm::AStarPathBuilder_UseCostMap_TinyData builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

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
				std::cout << r2::tab << "+ AStarPathBuilder_Use_ArrayBasedList_CostMap_STDVectorResultPath" << r2::linefeed2;

				r2util::StopWatch stop_watch;

				//
				// Build
				//
				std::vector<r2::Point> result_path;
				result_path.reserve( WORLD_MAP.GetWidth() * WORLD_MAP.GetHeight() );

				r2algorithm::AStarPathBuilder_Use_ArrayBasedList_CostMap_STDVectorResultPath builder( WORLD_MAP.GetWidth(), WORLD_MAP.GetHeight() );

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

			return r2::eTestResult::RunTest;
		};
	}
}