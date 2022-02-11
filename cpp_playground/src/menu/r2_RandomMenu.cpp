#include "pch.h"
#include "r2_RandomMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/c_random_test.h"
#include "test_cpp/std_random_test.h"

namespace r2
{
	MenuUp RandomMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, RandomMenu::GetTitle() ) );

		{
			ret->AddChild( '1', c_random_test::Rand::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', std_random_test::Basic::GetInstance() );
			ret->AddChild( 'w', std_random_test::StatusSaveAndLoad::GetInstance() );
			ret->AddChild( 'e', std_random_test::DiscreateDistribution::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestEndAction::ChangeScene;
				}
			);
		}

		return ret;
	}
}