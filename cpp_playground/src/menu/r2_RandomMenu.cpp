#include "pch.h"
#include "r2_RandomMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/c_random_test.h"
#include "test_cpp/std_random_test.h"

namespace r2
{
	MenuUp RandomMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, RandomMenu::GetTitle() ) );

		{
			ret->AddItem( '1', c_random_test::Rand::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'q', std_random_test::Basic::GetInstance() );
			ret->AddItem( 'w', std_random_test::StatusSaveAndLoad::GetInstance() );
			ret->AddItem( 'e', std_random_test::DiscreateDistribution::GetInstance() );


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