#include "ConsoleWindowMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/console_window_test.h"

#include "WindowsMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2cm::MenuUp ConsoleWindowMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', console_window_test::BufferInfo() );


		ret->AddLineFeed();


		ret->AddItem( '2', console_window_test::ChangeWindowSize() );
		ret->AddItem( '3', console_window_test::FullScreen() );
		ret->AddItem( '4', console_window_test::Focus() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'q', console_window_test::WindowPosition() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'a', console_window_test::ChangeWindowName() );
		ret->AddItem( 's', console_window_test::HideTitleBar() );
		ret->AddItem( 'd', console_window_test::HideScrollBar() );
		ret->AddItem( 'f', console_window_test::DisableMaximize() );
		ret->AddItem( 'g', console_window_test::LockWindowResizingByDragging() );
		ret->AddItem( 'h', console_window_test::MenuItem() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'z', console_window_test::CursorMove() );
		ret->AddItem( 'x', console_window_test::CursorVisibility() );
		ret->AddItem( 'c', console_window_test::QuickEdit() );


		ret->AddSplit();


		ret->AddMenu<WindowsMenu>( 27 );
	}

	return ret;
}