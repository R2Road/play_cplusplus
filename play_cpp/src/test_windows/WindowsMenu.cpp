#include "WindowsMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/console_window_input_test.h"
#include "item/windows_terminal_message_test.h"
#include "item/windows_screen_buffer_test.h"
#include "item/windows_sound_test.h"
#include "item/windows_terminal_dc_test.h"
#include "item/windows_terminal_font_test.h"

#include "ConsoleTextColorMenu.h"
#include "WindowsTerminalBasicMenu.h"
#include "FlickeringResearchMenu.h"
#include "RootMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2tm::TitleFunctionT WindowsMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Windows";
	};
}
r2tm::DescriptionFunctionT WindowsMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT WindowsMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddMenu( '1', WindowsTerminalBasicMenu() );
		ret->AddMenu( '2', ConsoleTextColorMenu() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'e', windows_terminal_input_test::WindowInput_ReadConsoleInput() );
		ret->AddItem( 'r', windows_terminal_input_test::WindowInput_GetKeyState() );
		ret->AddItem( 't', windows_terminal_input_test::WindowInput_GetKeyboardState() );
		ret->AddItem( 'y', windows_terminal_input_test::WindowInput_GetAsyncKeyStates() );


		ret->AddLineFeed();


		ret->AddItem( 'u', windows_terminal_message_test::ConsoleControlHandler() );
		ret->AddItem( 'i', windows_terminal_message_test::MessageHook() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'a', windows_screen_buffer_test::FillBuffer() );
		ret->AddItem( 's', windows_screen_buffer_test::Write2Buffer_WriteConsole() );
		ret->AddItem( 'd', windows_screen_buffer_test::Write2Buffer_WriteConsoleOutput() );
		ret->AddItem( 'f', windows_screen_buffer_test::DoubleBuffering() );
		ret->AddItem( 'g', windows_screen_buffer_test::ReadConsoleOutputTest() );
		ret->AddItem( 'h', windows_screen_buffer_test::ETCTest() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddMenu( 'z', FlickeringResearchMenu() );
		ret->AddItem( 'x', windows_terminal_font_test::FontInfo() );
		ret->AddItem( 'c', windows_terminal_font_test::FontChange() );
		ret->AddItem( 'v', windows_terminal_dc_test::Pixel() );
		ret->AddItem( 'b', windows_sound_test::PlaySoundTest() );
		ret->AddItem( 'n', windows_sound_test::BeepTest() );


		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}