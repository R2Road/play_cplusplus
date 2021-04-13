#include "pch.h"
#include "r2_PointerTestScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "pointer_test.h"

namespace r2
{
	SceneUp PointerTestScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Pointer" ) );

		{
			ret->AddChild( '1', pointer_test::Basic::GetInstance() );
			ret->AddChild( '2', pointer_test::ConstPointer::GetInstance() );

			ret->AddChild(
				27
				, []()->const char* { return "\nESC : Return To Root"; }
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