#include "pch.h"
#include "r2_TimeMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/time_1_test.h"
#include "test_cpp/time_2_test.h"
#include "test_cpp/time_3_test.h"

namespace r2
{
	MenuUp TimeMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', time_test::CTime::GetInstance() );
			ret->AddChild( '2', time_test::WindowTime::GetInstance() );
			ret->AddChild( '3', time_test::Chrono::GetInstance() );


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