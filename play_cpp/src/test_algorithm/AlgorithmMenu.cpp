#include "AlgorithmMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_algorithm/item/algorithm_bubble_sort_test.h"
#include "test_algorithm/item/algorithm_selection_sort_test.h"
#include "test_algorithm/item/algorithm_insertion_sort_test.h"

#include "test_algorithm/item/algorithm_astar_test.h"
#include "test_algorithm/item/algorithm_etc_test.h"

#include "MazeGenerationMenu.h"
#include "ProceduralTerrainGenerationMenu.h"
#include "menu_root.h"

r2tm::TitleFunctionT AlgorithmMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Algorithm";
	};
}
r2tm::DescriptionFunctionT AlgorithmMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT AlgorithmMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', algorithm_selection_sort_test::Case1() );
		mp->AddItem( '2', algorithm_selection_sort_test::Case2() );

		mp->AddLineFeed();

		mp->AddItem( '3', algorithm_bubble_sort_test::Basic() );

		mp->AddLineFeed();

		mp->AddItem( '4', algorithm_insertion_sort_test::Basic() );


		mp->AddSplit();


		mp->AddItem( 'w', algorithm_astar_test::Basic() );
		mp->AddItem( 'e', algorithm_astar_test::Use_STDListSplice() );
		mp->AddItem( 'r', algorithm_astar_test::Use_STDListSplice_STDVectorResultPath() );
		mp->AddItem( 't', algorithm_astar_test::Use_STDListSplice_DecreaseCloseList_STDVectorResultPath() );
		mp->AddItem( 'y', algorithm_astar_test::Use_CostMap_STDListSplice_STDVectorResultPath() );
		mp->AddItem( 'u', algorithm_astar_test::Use_TinyCostMap_STDListSplice_STDVectorResultPath() );
		mp->AddItem( 'i', algorithm_astar_test::Use_ArrayBasedList_TinyCostMap_STDVectorResultPath() );

		mp->AddLineFeed();

		mp->AddItem( 'o', algorithm_astar_test::PerformanceTest() );


		mp->AddSplit();


		mp->AddItem( 'a', algorithm_etc_test::DJB2() );


		mp->AddSplit();


		mp->AddMenu( 'z', MazeGenerationMenu() );
		mp->AddMenu( 'x', ProceduralTerrainGenerationMenu() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}