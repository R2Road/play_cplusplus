#include "pch.h"
#include "ConsoleWindowMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "item/console_window_test.h"

#include "TestWindowsMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

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
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TestWindowsMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}