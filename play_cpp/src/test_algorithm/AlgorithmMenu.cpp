#include "AlgorithmMenu.h"

#include "r2cm/r2cm_Director.h"

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
		ret->AddItem( '1', algorithm_selection_sort_test::Case1() );
		ret->AddItem( '2', algorithm_selection_sort_test::Case2() );

		ret->AddLineFeed();

		ret->AddItem( '3', algorithm_bubble_sort_test::Basic() );

		ret->AddLineFeed();

		ret->AddItem( '4', algorithm_insertion_sort_test::Basic() );


		ret->AddSplit();


		ret->AddItem( 'w', algorithm_astar_test::Basic() );
		ret->AddItem( 'e', algorithm_astar_test::Use_STDListSplice() );
		ret->AddItem( 'r', algorithm_astar_test::Use_STDListSplice_STDVectorResultPath() );
		ret->AddItem( 't', algorithm_astar_test::Use_STDListSplice_DecreaseCloseList_STDVectorResultPath() );
		ret->AddItem( 'y', algorithm_astar_test::Use_CostMap_STDListSplice_STDVectorResultPath() );
		ret->AddItem( 'u', algorithm_astar_test::Use_TinyCostMap_STDListSplice_STDVectorResultPath() );
		ret->AddItem( 'i', algorithm_astar_test::Use_ArrayBasedList_TinyCostMap_STDVectorResultPath() );

		ret->AddLineFeed();

		ret->AddItem( 'o', algorithm_astar_test::PerformanceTest() );


		ret->AddSplit();


		ret->AddItem( 'a', algorithm_etc_test::DJB2() );


		ret->AddSplit();


		ret->AddMenu<MazeGenerationMenu>( 'z' );
		ret->AddMenu<ProceduralTerrainGenerationMenu>( 'x' );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}