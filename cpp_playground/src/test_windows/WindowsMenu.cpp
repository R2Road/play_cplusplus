#include "WindowsMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "item/console_buffer_test.h"
#include "item/console_window_etc_test.h"
#include "item/console_window_input_test.h"
#include "item/console_window_message_test.h"
#include "item/windows_sound_test.h"

#include "ConsoleTextColorMenu.h"
#include "ConsoleWindowMenu.h"
#include "FlickeringResearchMenu.h"
#include "RootMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2cm::MenuUp TestWindowsMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem(
			'1'
			, []()->const char* { return ConsoleWindowMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( ConsoleWindowMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'2'
			, []()->const char* { return ConsoleTextColorMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( ConsoleTextColorMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);

		ret->AddLineFeed();
		ret->AddLineFeed();

		ret->AddItem( 'e', console_window_input_test::WindowInput_ReadConsoleInput::GetInstance() );
		ret->AddItem( 'r', console_window_input_test::WindowInput_GetKeyState::GetInstance() );
		ret->AddItem( 't', console_window_input_test::WindowInput_GetKeyboardState::GetInstance() );
		ret->AddItem( 'y', console_window_input_test::WindowInput_GetAsyncKeyStates::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'u', console_window_message_test::ConsoleControlHandler::GetInstance() );
		ret->AddItem( 'i', console_window_message_test::MessageHook::GetInstance() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'a', console_buffer_test::FillBuffer::GetInstance() );
		ret->AddItem( 's', console_buffer_test::Write2Buffer_WriteConsole::GetInstance() );
		ret->AddItem( 'd', console_buffer_test::Write2Buffer_WriteConsoleOutput::GetInstance() );
		ret->AddItem( 'f', console_buffer_test::DoubleBuffering::GetInstance() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem(
			'z'
			, []()->const char* { return FlickeringResearchMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( FlickeringResearchMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem( 'x', console_window_etc_test::FontInfo::GetInstance() );
		ret->AddItem( 'c', console_window_etc_test::FontChange::GetInstance() );
		ret->AddItem( 'v', console_window_etc_test::Pixel::GetInstance() );
		ret->AddItem( 'b', windows_sound_test::PlaySoundTest::GetInstance() );
		ret->AddItem( 'n', windows_sound_test::BeepTest::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( RootMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}