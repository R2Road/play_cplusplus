#include "pch.h"
#include "r2_TimeMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
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
			ret->AddItem( '1', c_time_test::Basic::GetInstance() );
			ret->AddItem( '2', c_time_test::Y_M_D_H_S::GetInstance() );
			ret->AddItem( '3', c_time_test::Clock::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'q', window_time_test::Basic::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'w', std_chrono_test::Epoch::GetInstance() );
			ret->AddItem( 'e', std_chrono_test::Chrono::GetInstance() );


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