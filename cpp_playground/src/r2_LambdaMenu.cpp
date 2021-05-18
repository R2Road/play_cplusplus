#include "pch.h"
#include "r2_LambdaMenu.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "lambda_test.h"

namespace r2
{
	MenuUp LambdaMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', lambda_test::CaptureValue::GetInstance() );
			ret->AddChild( '2', lambda_test::CaptureValueWithMutable::GetInstance() );
			ret->AddChild( '3', lambda_test::CaptureReference::GetInstance() );
			ret->AddChild( '4', lambda_test::CaptureUniquePtr::GetInstance() );


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