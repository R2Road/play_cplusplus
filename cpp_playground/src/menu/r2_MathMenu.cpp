#include "pch.h"
#include "r2_MathMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/vector3_test.h"

namespace r2
{
	MenuUp MathMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', vector3_test::OperatorPlus::GetInstance() );
			ret->AddChild( '2', vector3_test::OperatorPlusEqual::GetInstance() );
			ret->AddChild( '3', vector3_test::OperatorMinus::GetInstance() );


			ret->AddLineFeed();


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}