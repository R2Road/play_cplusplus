#include "pch.h"
#include "r2_STDNumericMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_STDMenu.h"

#include "test_cpp/std_numeric_test.h"

namespace r2
{
	MenuUp STDNumericMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', std_numeric_test::Accumulate_Number::GetInstance() );
			ret->AddChild( '2', std_numeric_test::Accumulate_String::GetInstance() );
			ret->AddChild( '3', std_numeric_test::Partial_Sum::GetInstance() );
			ret->AddChild( '4', std_numeric_test::FillSequenceNumber::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::STDMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}