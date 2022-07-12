#include "AlgorithmMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_algorithm/item/algorithm_bubble_sort_test.h"
#include "test_algorithm/item/algorithm_selection_sort_test.h"
#include "test_algorithm/item/algorithm_insertion_sort_test.h"

#include "test_algorithm/item/algorithm_astar_test.h"
#include "test_algorithm/item/algorithm_etc_test.h"

#include "MazeGenerationMenu.h"
#include "ProceduralTerrainGenerationMenu.h"
#include "RootMenu.h"

r2cm::MenuUp AlgorithmMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', algorithm_selection_sort_test::Case1::GetInstance() );
		ret->AddItem( '2', algorithm_selection_sort_test::Case2::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( '3', algorithm_bubble_sort_test::Basic::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( '4', algorithm_insertion_sort_test::Basic::GetInstance() );


		ret->AddSplit();


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


		ret->AddItem( 'a', algorithm_etc_test::DJB2::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			'z'
			, []()->const char* { return MazeGenerationMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( MazeGenerationMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'x'
			, []()->const char* { return ProceduralTerrainGenerationMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( ProceduralTerrainGenerationMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}