#include "pch.h"
#include "r2_EnumScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "enum_test.h"

namespace r2
{
	MenuUp EnumScene::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', enum_test::Basic::GetInstance() );
			ret->AddChild( '2', enum_test::Convert::GetInstance() );


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


			ret->AddSplit();
		}

		return ret;
	}
}