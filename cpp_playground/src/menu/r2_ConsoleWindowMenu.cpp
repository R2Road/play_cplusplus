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
	r2cm::MenuUp ConsoleWindowMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', console_window_test::BufferInfo::GetInstance() );

			ret->AddLineFeed();

			ret->AddItem( '2', console_window_test::ChangeWindowSize::GetInstance() );
			ret->AddItem( '3', console_window_test::FullScreen::GetInstance() );

			ret->AddLineFeed();

			ret->AddItem( 'q', console_window_test::WindowPosition::GetInstance() );

			ret->AddLineFeed();

			ret->AddItem( 'a', console_window_test::ChangeWindowName::GetInstance() );
			ret->AddItem( 's', console_window_test::HideTitleBar::GetInstance() );
			ret->AddItem( 'd', console_window_test::HideScrollBar::GetInstance() );
			ret->AddItem( 'f', console_window_test::LockWindowResizingByDragging::GetInstance() );
			ret->AddItem( 'g', console_window_test::MenuItem::GetInstance() );

			ret->AddLineFeed();
			ret->AddLineFeed();

			ret->AddItem( 'z', console_window_test::CursorMove::GetInstance() );
			ret->AddItem( 'x', console_window_test::CursorVisibility::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::ConsoleMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}