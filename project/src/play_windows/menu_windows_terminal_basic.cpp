#include "menu_windows_terminal_basic.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_windows_terminal_basic.hpp"

#include "menu_windows.hpp"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2tm::TitleFunctionT Menu_Windows_Terminal_Basic::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Windows Terminal : Basic";
	};
}
r2tm::DescriptionFunctionT Menu_Windows_Terminal_Basic::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Windows_Terminal_Basic::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_windows_terminal_basic::BufferInfo() );


		mp->AddLineFeed();


		mp->AddItem( '2', play_windows_terminal_basic::ChangeWindowSize() );
		mp->AddItem( '3', play_windows_terminal_basic::FullScreen() );
		mp->AddItem( '4', play_windows_terminal_basic::Focus() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'q', play_windows_terminal_basic::WindowPosition() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'a', play_windows_terminal_basic::ChangeWindowName() );
		mp->AddItem( 's', play_windows_terminal_basic::HideTitleBar() );
		mp->AddItem( 'd', play_windows_terminal_basic::HideScrollBar() );
		mp->AddItem( 'f', play_windows_terminal_basic::DisableMaximize() );
		mp->AddItem( 'g', play_windows_terminal_basic::LockWindowResizingByDragging() );
		mp->AddItem( 'h', play_windows_terminal_basic::MenuItem() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'z', play_windows_terminal_basic::CursorMove() );
		mp->AddItem( 'x', play_windows_terminal_basic::CursorVisibility() );
		mp->AddItem( 'c', play_windows_terminal_basic::QuickEdit() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Windows() );
	};
}