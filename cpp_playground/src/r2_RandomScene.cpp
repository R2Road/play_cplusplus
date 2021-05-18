#include "pch.h"
#include "r2_RandomScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "random_test.h"

namespace r2
{
	MenuUp RandomScene::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, RandomScene::GetTitle() ) );

		{
			ret->AddChild( '1', random_test::Basic::GetInstance() );
			ret->AddChild( '2', random_test::StatusSaveAndLoad::GetInstance() );


			ret->AddSplit();


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