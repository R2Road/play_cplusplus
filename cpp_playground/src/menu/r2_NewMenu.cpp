#include "pch.h"
#include "r2_NewMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/new_test.h"

namespace r2
{
	MenuUp NewMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', new_test::Basic::GetInstance() );
			ret->AddChild( '2', new_test::PlacementNew::GetInstance() );


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