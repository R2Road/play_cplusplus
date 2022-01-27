#include "pch.h"
#include "r2_RandomMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/std_random_test.h"

namespace r2
{
	MenuUp RandomMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, RandomMenu::GetTitle() ) );

		{
			ret->AddChild( '1', std_random_test::Basic::GetInstance() );
			ret->AddChild( '2', std_random_test::StatusSaveAndLoad::GetInstance() );
			ret->AddChild( '3', std_random_test::DiscreateDistribution::GetInstance() );


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