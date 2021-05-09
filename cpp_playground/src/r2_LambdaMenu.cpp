#include "pch.h"
#include "r2_LambdaMenu.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "lambda_test.h"

namespace r2
{
	SceneUp LambdaMenu::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, GetTitle() ) );

		{
			ret->AddChild( '1', lambda_test::CaptureValue::GetInstance() );
			ret->AddChild( '2', lambda_test::CaptureReference::GetInstance() );
			ret->AddChild( '3', lambda_test::CaptureUniquePtr::GetInstance() );
			ret->AddChild( '4', lambda_test::TestETC::GetInstance() );


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