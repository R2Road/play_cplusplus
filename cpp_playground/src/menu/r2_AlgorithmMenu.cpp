#include "pch.h"
#include "r2_AlgorithmMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/algorithm_selection_sort_test.h"
#include "test_cpp/algorithm_bubble_sort_test.h"

namespace r2
{
	MenuUp AlgorithmMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', algorithm_selection_sort_test::Basic::GetInstance() );
			ret->AddChild( '2', algorithm_bubble_sort_test::Basic::GetInstance() );


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