#include "r2_RandomTestScene.h"

#include <iostream>

#include "r2_Director.h"
#include "r2_RootScene.h"
#include "random_test.h"

namespace r2
{
	SceneUp RandomTestScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Random" ) );

		{
			ret->AddChild( '1', random_test::Basic::GetInstance() );
			ret->AddChild( '2', random_test::StatusSaveAndLoad::GetInstance() );

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