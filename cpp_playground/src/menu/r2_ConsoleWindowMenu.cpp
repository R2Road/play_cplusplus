#include "pch.h"
#include "r2_ConsoleWindowMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_ConsoleMenu.h"

#include "test_cpp/console_window_test.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

namespace r2
{
	MenuUp ConsoleWindowMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', console_window_test::BufferInfo::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( '2', console_window_test::ChangeWindowSize::GetInstance() );
			ret->AddChild( '3', console_window_test::FullScreen::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'q', console_window_test::WindowPosition::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'a', console_window_test::ChangeWindowName::GetInstance() );
			ret->AddChild( 's', console_window_test::HideTitleBar::GetInstance() );
			ret->AddChild( 'd', console_window_test::HideScrollBar::GetInstance() );
			ret->AddChild( 'f', console_window_test::LockWindowResizingByDragging::GetInstance() );
			ret->AddChild( 'g', console_window_test::MenuItem::GetInstance() );

			ret->AddLineFeed();
			ret->AddLineFeed();

			ret->AddChild( 'z', console_window_test::CursorMove::GetInstance() );
			ret->AddChild( 'x', console_window_test::CursorVisibility::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::ConsoleMenu::Create( director ) );
					return eTestEndAction::ChangeScene;
				}
			);
		}

		return ret;
	}
}