#include "pch.h"
#include "r2_NewScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "new_test.h"

namespace r2
{
	MenuUp NewScene::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', new_test::Basic::GetInstance() );
			ret->AddChild( '2', new_test::PlacementNew::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}