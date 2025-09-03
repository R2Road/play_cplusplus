#include "menu_windows.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_windows_terminal_input.hpp"
#include "play_windows_terminal_message.hpp"
#include "play_windows_terminal_screen_buffer.hpp"
#include "play_windows_sound.hpp"
#include "play_windows_terminal_dc.hpp"

#include "menu_windows_terminal_fond_and_color.hpp"
#include "menu_windows_terminal_basic.hpp"
#include "menu_windows_terminal_flickering_research.hpp"

#include "menu_root.hpp"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2tm::TitleFunctionT Menu_Windows::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Windows";
	};
}
r2tm::DescriptionFunctionT Menu_Windows::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Windows::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMenu( '1', Menu_Windows_Terminal_Basic() );
		mp->AddMenu( '2', Menu_Windows_Terminal_Font_And_Color() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'e', play_windows_terminal_input::WindowInput_ReadConsoleInput() );
		mp->AddItem( 'r', play_windows_terminal_input::WindowInput_GetKeyState() );
		mp->AddItem( 't', play_windows_terminal_input::WindowInput_GetKeyboardState() );
		mp->AddItem( 'y', play_windows_terminal_input::WindowInput_GetAsyncKeyStates() );


		mp->AddLineFeed();


		mp->AddItem( 'u', play_windows_terminal_message::ConsoleControlHandler() );
		mp->AddItem( 'i', play_windows_terminal_message::MessageHook() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'a', play_windows_terminal_screen_buffer::FillBuffer() );
		mp->AddItem( 's', play_windows_terminal_screen_buffer::Write2Buffer_WriteConsole() );
		mp->AddItem( 'd', play_windows_terminal_screen_buffer::Write2Buffer_WriteConsoleOutput() );
		mp->AddItem( 'f', play_windows_terminal_screen_buffer::DoubleBuffering() );
		mp->AddItem( 'g', play_windows_terminal_screen_buffer::ReadConsoleOutputTest() );
		mp->AddItem( 'h', play_windows_terminal_screen_buffer::ETCTest() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddMenu( 'z', Menu_Windows_Terminal_Flickering_Research() );
		mp->AddItem( 'x', play_windows_terminal_dc::Pixel() );
		mp->AddItem( 'c', play_windows_sound::PlaySoundTest() );
		mp->AddItem( 'v', play_windows_sound::BeepTest() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}