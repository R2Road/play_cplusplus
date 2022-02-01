#include "pch.h"
#include "r2_TimeMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/c_time_test.h"
#include "test_cpp/std_chrono_test.h"
#include "test_cpp/window_time_test.h"

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


			ret->AddChild( 'q', window_time_test::Basic::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'w', std_chrono_test::Epoch::GetInstance() );
			ret->AddChild( 'e', std_chrono_test::Chrono::GetInstance() );


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