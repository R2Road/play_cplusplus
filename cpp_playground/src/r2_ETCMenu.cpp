#include "pch.h"
#include "r2_ETCMenu.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "etc_0_test.h"

namespace r2
{
	SceneUp ETCMenu::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', etc_test::XOR_Swap::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RootScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}