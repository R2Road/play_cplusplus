#include "WindowsTerminalBasicMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/window_terminal_basic_test.h"

#include "WindowsMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2tm::TitleFunctionT WindowsTerminalBasicMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Windows Terminal : Basic";
	};
}
r2tm::DescriptionFunctionT WindowsTerminalBasicMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT WindowsTerminalBasicMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', windows_terminal_basic_test::BufferInfo() );


		ret->AddLineFeed();


		ret->AddItem( '2', windows_terminal_basic_test::ChangeWindowSize() );
		ret->AddItem( '3', windows_terminal_basic_test::FullScreen() );
		ret->AddItem( '4', windows_terminal_basic_test::Focus() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'q', windows_terminal_basic_test::WindowPosition() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'a', windows_terminal_basic_test::ChangeWindowName() );
		ret->AddItem( 's', windows_terminal_basic_test::HideTitleBar() );
		ret->AddItem( 'd', windows_terminal_basic_test::HideScrollBar() );
		ret->AddItem( 'f', windows_terminal_basic_test::DisableMaximize() );
		ret->AddItem( 'g', windows_terminal_basic_test::LockWindowResizingByDragging() );
		ret->AddItem( 'h', windows_terminal_basic_test::MenuItem() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'z', windows_terminal_basic_test::CursorMove() );
		ret->AddItem( 'x', windows_terminal_basic_test::CursorVisibility() );
		ret->AddItem( 'c', windows_terminal_basic_test::QuickEdit() );


		ret->AddSplit();


		ret->AddMenu( 27, WindowsMenu() );
	};
}