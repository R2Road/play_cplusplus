#include "pch.h"
#include "r2_TimeMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/c_time_test.h"
#include "test_cpp/time_2_test.h"
#include "test_cpp/time_3_test.h"

namespace r2
{
	MenuUp TimeMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', c_time_test::Basic::GetInstance() );
			ret->AddChild( '2', c_time_test::Y_M_D_H_S::GetInstance() );
			ret->AddChild( '3', c_time_test::Clock::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', time_test::WindowTime::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'w', time_test::Chrono::GetInstance() );


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