#include "WindowsMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "item/windows_terminal_input_test.h"
#include "item/windows_terminal_message_test.h"
#include "item/windows_screen_buffer_test.h"
#include "item/windows_sound_test.h"
#include "item/windows_terminal_dc_test.h"

#include "WindowsTerminalFondAndTextColorMenu.h"
#include "WindowsTerminalBasicMenu.h"
#include "FlickeringResearchMenu.h"
#include "menu_root.hpp"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMenu( '1', WindowsTerminalBasicMenu() );
		mp->AddMenu( '2', WindowsTerminalFondAndTextColorMenu() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'e', windows_terminal_input_test::WindowInput_ReadConsoleInput() );
		mp->AddItem( 'r', windows_terminal_input_test::WindowInput_GetKeyState() );
		mp->AddItem( 't', windows_terminal_input_test::WindowInput_GetKeyboardState() );
		mp->AddItem( 'y', windows_terminal_input_test::WindowInput_GetAsyncKeyStates() );


		mp->AddLineFeed();


		mp->AddItem( 'u', windows_terminal_message_test::ConsoleControlHandler() );
		mp->AddItem( 'i', windows_terminal_message_test::MessageHook() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'a', windows_screen_buffer_test::FillBuffer() );
		mp->AddItem( 's', windows_screen_buffer_test::Write2Buffer_WriteConsole() );
		mp->AddItem( 'd', windows_screen_buffer_test::Write2Buffer_WriteConsoleOutput() );
		mp->AddItem( 'f', windows_screen_buffer_test::DoubleBuffering() );
		mp->AddItem( 'g', windows_screen_buffer_test::ReadConsoleOutputTest() );
		mp->AddItem( 'h', windows_screen_buffer_test::ETCTest() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddMenu( 'z', FlickeringResearchMenu() );
		mp->AddItem( 'x', windows_terminal_dc_test::Pixel() );
		mp->AddItem( 'c', windows_sound_test::PlaySoundTest() );
		mp->AddItem( 'v', windows_sound_test::BeepTest() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}