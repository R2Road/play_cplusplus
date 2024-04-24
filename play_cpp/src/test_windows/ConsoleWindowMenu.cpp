#include "ConsoleWindowMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/console_window_test.h"

#include "WindowsMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2tm::TitleFunctionT ConsoleWindowMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Basic";
	};
}
r2tm::DescriptionFunctionT ConsoleWindowMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT ConsoleWindowMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', window_terminal_basic_test::BufferInfo() );


		ret->AddLineFeed();


		ret->AddItem( '2', window_terminal_basic_test::ChangeWindowSize() );
		ret->AddItem( '3', window_terminal_basic_test::FullScreen() );
		ret->AddItem( '4', window_terminal_basic_test::Focus() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'q', window_terminal_basic_test::WindowPosition() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'a', window_terminal_basic_test::ChangeWindowName() );
		ret->AddItem( 's', window_terminal_basic_test::HideTitleBar() );
		ret->AddItem( 'd', window_terminal_basic_test::HideScrollBar() );
		ret->AddItem( 'f', window_terminal_basic_test::DisableMaximize() );
		ret->AddItem( 'g', window_terminal_basic_test::LockWindowResizingByDragging() );
		ret->AddItem( 'h', window_terminal_basic_test::MenuItem() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'z', window_terminal_basic_test::CursorMove() );
		ret->AddItem( 'x', window_terminal_basic_test::CursorVisibility() );
		ret->AddItem( 'c', window_terminal_basic_test::QuickEdit() );


		ret->AddSplit();


		ret->AddMenu( 27, WindowsMenu() );
	};
}