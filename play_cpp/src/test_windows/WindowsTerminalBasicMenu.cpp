#include "WindowsTerminalBasicMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "item/windows_terminal_basic_test.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', windows_terminal_basic_test::BufferInfo() );


		mp->AddLineFeed();


		mp->AddItem( '2', windows_terminal_basic_test::ChangeWindowSize() );
		mp->AddItem( '3', windows_terminal_basic_test::FullScreen() );
		mp->AddItem( '4', windows_terminal_basic_test::Focus() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'q', windows_terminal_basic_test::WindowPosition() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'a', windows_terminal_basic_test::ChangeWindowName() );
		mp->AddItem( 's', windows_terminal_basic_test::HideTitleBar() );
		mp->AddItem( 'd', windows_terminal_basic_test::HideScrollBar() );
		mp->AddItem( 'f', windows_terminal_basic_test::DisableMaximize() );
		mp->AddItem( 'g', windows_terminal_basic_test::LockWindowResizingByDragging() );
		mp->AddItem( 'h', windows_terminal_basic_test::MenuItem() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'z', windows_terminal_basic_test::CursorMove() );
		mp->AddItem( 'x', windows_terminal_basic_test::CursorVisibility() );
		mp->AddItem( 'c', windows_terminal_basic_test::QuickEdit() );


		mp->AddSplit();


		mp->AddMenu( 27, WindowsMenu() );
	};
}