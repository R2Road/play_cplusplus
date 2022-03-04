#include "pch.h"
#include "r2_AlgorithmMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_algorithm/algorithm_bubble_sort_test.h"
#include "test_algorithm/algorithm_selection_sort_test.h"
#include "test_algorithm/algorithm_insertion_sort_test.h"

#include "test_algorithm/algorithm_astar_test.h"
#include "test_algorithm/algorithm_maze_test.h"

namespace r2
{
	MenuUp AlgorithmMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', algorithm_selection_sort_test::Case1::GetInstance() );
			ret->AddItem( '2', algorithm_selection_sort_test::Case2::GetInstance() );

			ret->AddLineFeed();

			ret->AddItem( '3', algorithm_bubble_sort_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddItem( '4', algorithm_insertion_sort_test::Basic::GetInstance() );


			ret->AddSplit();


			ret->AddItem( 'q', algorithm_maze_test::Basic::GetInstance() );
			ret->AddItem( 'w', algorithm_astar_test::Basic::GetInstance() );
			ret->AddItem( 'e', algorithm_astar_test::Use_STDListSplice::GetInstance() );
			ret->AddItem( 'r', algorithm_astar_test::Use_STDListSplice_STDVectorResultPath::GetInstance() );
			ret->AddItem( 't', algorithm_astar_test::Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::GetInstance() );
			ret->AddItem( 'y', algorithm_astar_test::Use_CostMap_STDListSplice_STDVectorResultPath::GetInstance() );
			ret->AddItem( 'u', algorithm_astar_test::Use_TinyCostMap_STDListSplice_STDVectorResultPath::GetInstance() );
			ret->AddItem( 'i', algorithm_astar_test::Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::GetInstance() );

			ret->AddLineFeed();

			ret->AddItem( 'o', algorithm_astar_test::PerformanceTest::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}