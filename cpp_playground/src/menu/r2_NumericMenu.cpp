#include "pch.h"
#include "r2_NumericMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/numeric_test.h"

namespace r2
{
	MenuUp NumericMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', numeric_test::Accumulate_Number::GetInstance() );
			ret->AddChild( '2', numeric_test::Accumulate_String::GetInstance() );
			ret->AddChild( '3', numeric_test::Partial_Sum::GetInstance() );


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