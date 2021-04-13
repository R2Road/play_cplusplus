#include "pch.h"
#include "r2_AlignScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "align_test.h"

namespace r2
{
	SceneUp AlignScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Root" ) );

		{
			ret->AddChild( '1', align_test::Basic::GetInstance() );
			ret->AddChild( '2', align_test::MixedStruct::GetInstance() );
			ret->AddChild( '3', align_test::AlignAs::GetInstance() );
			ret->AddChild( '4', align_test::Align::GetInstance() );

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