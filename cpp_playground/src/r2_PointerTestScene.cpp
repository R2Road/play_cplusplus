#include "pch.h"
#include "r2_PointerTestScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "pointer_test.h"

namespace r2
{
	MenuUp PointerTestScene::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, "Pointer" ) );

		{
			ret->AddChild( '1', pointer_test::Basic::GetInstance() );
			ret->AddChild( '2', pointer_test::ConstPointer::GetInstance() );


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