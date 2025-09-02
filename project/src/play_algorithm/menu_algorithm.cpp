#include "menu_algorithm.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_algorithm_bubble_sort.hpp"
#include "play_algorithm_selection_sort.hpp"
#include "play_algorithm_insertion_sort.hpp"

#include "play_algorithm_astar.hpp"
#include "play_algorithm_etc.hpp"

#include "menu_maze_generation.hpp"
#include "menu_procedural_terrain_generation.hpp"
#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_Algorithm::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Algorithm";
	};
}
r2tm::DescriptionFunctionT Menu_Algorithm::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Algorithm::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_algorithm_selection_sort::Case1() );
		mp->AddItem( '2', play_algorithm_selection_sort::Case2() );

		mp->AddLineFeed();

		mp->AddItem( '3', play_algorithm_bubble_sort::Basic() );

		mp->AddLineFeed();

		mp->AddItem( '4', play_algorithm_insertion_sort::Basic() );


		mp->AddSplit();


		mp->AddItem( 'w', play_algorithm_astar::Basic() );
		mp->AddItem( 'e', play_algorithm_astar::Use_STDListSplice() );
		mp->AddItem( 'r', play_algorithm_astar::Use_STDListSplice_STDVectorResultPath() );
		mp->AddItem( 't', play_algorithm_astar::Use_STDListSplice_DecreaseCloseList_STDVectorResultPath() );
		mp->AddItem( 'y', play_algorithm_astar::Use_CostMap_STDListSplice_STDVectorResultPath() );
		mp->AddItem( 'u', play_algorithm_astar::Use_TinyCostMap_STDListSplice_STDVectorResultPath() );
		mp->AddItem( 'i', play_algorithm_astar::Use_ArrayBasedList_TinyCostMap_STDVectorResultPath() );

		mp->AddLineFeed();

		mp->AddItem( 'o', play_algorithm_astar::PerformanceTest() );


		mp->AddSplit();


		mp->AddItem( 'a', play_algorithm_etc::DJB2() );


		mp->AddSplit();


		mp->AddMenu( 'z', Menu_MazeGeneration() );
		mp->AddMenu( 'x', Menu_ProceduralTerrainGeneration() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}