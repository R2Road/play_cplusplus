#include "pch.h"
#include "r2_AlignOfScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "alignof_test.h"

namespace r2
{
	SceneUp AlignOfScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Align Of" ) );

		{
			ret->AddChild( '1', alignof_test::Basic::GetInstance() );
			ret->AddChild( '2', alignof_test::MixedStruct::GetInstance() );

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