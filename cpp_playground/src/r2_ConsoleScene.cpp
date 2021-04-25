#include "pch.h"
#include "r2_ConsoleScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "console_test.h"

namespace r2
{
	SceneUp ConsoleScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', console_test::GetWindowSize::GetInstance() );
			ret->AddChild( '2', console_test::ChangeWindowSize::GetInstance() );
			ret->AddChild( '3', console_test::ChangeWindowPosition::GetInstance() );
			ret->AddChild( '4', console_test::ChangeWindowName::GetInstance() );
			ret->AddChild( '5', console_test::MoveCursor::GetInstance() );
			ret->AddChild( '6', console_test::TextColor1::GetInstance() );
			ret->AddChild( '7', console_test::TextColor2::GetInstance() );
			
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