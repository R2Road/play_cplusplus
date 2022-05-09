#include "pch.h"
#include "r2_LambdaMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "C_CPP_Menu.h"
#include "test_cpp/item/lambda_test.h"

namespace r2
{
	r2cm::MenuUp LambdaMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

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
				, [&director]()->r2cm::eItemLeaveAction
				{
					director.Setup( C_CPP_Menu::Create( director ) );
					return r2cm::eItemLeaveAction::None;
				}
			);
		}

		return ret;
	}
}