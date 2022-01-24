#include "pch.h"
#include "r2_AlgorithmMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
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
			ret->AddChild( '1', algorithm_selection_sort_test::Case1::GetInstance() );
			ret->AddChild( '2', algorithm_selection_sort_test::Case2::GetInstance() );

			ret->AddChild( '3', algorithm_bubble_sort_test::Basic::GetInstance() );

			ret->AddChild( '4', algorithm_insertion_sort_test::Basic::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'q', algorithm_maze_test::Basic::GetInstance() );
			ret->AddChild( 'w', algorithm_astar_test::Basic::GetInstance() );
			ret->AddChild( 'e', algorithm_astar_test::UseSTDListSplice::GetInstance() );
			ret->AddChild( 'r', algorithm_astar_test::UseSTDListSplice_And_STDVectorResultPath::GetInstance() );
			ret->AddChild( 't', algorithm_astar_test::UseSTDListSplice_And_STDVectorResultPath_DecreaseCloseList::GetInstance() );
			ret->AddChild( 'y', algorithm_astar_test::UseCostMap::GetInstance() );
			ret->AddChild( 'u', algorithm_astar_test::UseCostMap_And_TinyData::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}