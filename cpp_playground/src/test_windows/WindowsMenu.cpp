#include "WindowsMenu.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Director.h"

#include "item/console_window_input_test.h"
#include "item/console_window_message_test.h"
#include "item/windows_screen_buffer_test.h"
#include "item/windows_sound_test.h"
#include "item/windows_terminal_dc_test.h"
#include "item/windows_terminal_font_test.h"

#include "ConsoleTextColorMenu.h"
#include "ConsoleWindowMenu.h"
#include "FlickeringResearchMenu.h"
#include "RootMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2cm::MenuUp WindowsMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddMenu<ConsoleWindowMenu>( '1' );
		ret->AddMenu<ConsoleTextColorMenu>( '2' );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'e', console_window_input_test::WindowInput_ReadConsoleInput() );
		ret->AddItem( 'r', console_window_input_test::WindowInput_GetKeyState() );
		ret->AddItem( 't', console_window_input_test::WindowInput_GetKeyboardState() );
		ret->AddItem( 'y', console_window_input_test::WindowInput_GetAsyncKeyStates() );


		ret->AddLineFeed();


		ret->AddItem( 'u', console_window_message_test::ConsoleControlHandler() );
		ret->AddItem( 'i', console_window_message_test::MessageHook() );


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


		ret->AddMenu<FlickeringResearchMenu>( 'z' );
		ret->AddItem( 'x', windows_terminal_font_test::FontInfo() );
		ret->AddItem( 'c', windows_terminal_font_test::FontChange() );
		ret->AddItem( 'v', windows_terminal_dc_test::Pixel() );
		ret->AddItem( 'b', windows_sound_test::PlaySoundTest() );
		ret->AddItem( 'n', windows_sound_test::BeepTest() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}