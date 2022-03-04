#include "pch.h"
#include "r2_LambdaMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/lambda_test.h"

namespace r2
{
	MenuUp LambdaMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', lambda_test::CaptureValue::GetInstance() );
			ret->AddItem( '2', lambda_test::CaptureValueWithMutable::GetInstance() );
			ret->AddItem( '3', lambda_test::CaptureReference::GetInstance() );
			ret->AddItem( '4', lambda_test::CaptureUniquePtr::GetInstance() );
			ret->AddItem( '5', lambda_test::CaptureValueWithAssign::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}