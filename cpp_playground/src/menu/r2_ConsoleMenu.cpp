#include "pch.h"
#include "r2_ConsoleMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"

#include "ConsoleTextColorMenu.h"
#include "r2_ConsoleWindowMenu.h"
#include "r2_RootMenu.h"

#include "test_cpp/console_buffer_test.h"
#include "test_cpp/console_input_test.h"
#include "test_cpp/console_test.h"
#include "test_cpp/console_window_input_test.h"
#include "test_cpp/console_window_message_test.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

namespace r2
{
	MenuUp ConsoleMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild(
				'1'
				, []()->const char* { return ConsoleWindowMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( ConsoleWindowMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
			ret->AddChild(
				'2'
				, []()->const char* { return ConsoleTextColorMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( ConsoleTextColorMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);

			ret->AddLineFeed();
			ret->AddLineFeed();

			ret->AddChild( 'a', console_test::FontInfo::GetInstance() );
			ret->AddChild( 's', console_test::FontChange::GetInstance() );
			ret->AddChild( 'd', console_window_input_test::WindowInput_ReadConsoleInput::GetInstance() );
			ret->AddChild( 'f', console_window_input_test::WindowInput_GetKeyState::GetInstance() );
			ret->AddChild( 'g', console_window_input_test::WindowInput_GetKeyboardState::GetInstance() );
			ret->AddChild( 'h', console_window_input_test::WindowInput_GetAsyncKeyStates::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'j', console_window_message_test::ConsoleControlHandler::GetInstance() );
			ret->AddChild( 'k', console_window_message_test::MessageHook::GetInstance() );


			ret->AddLineFeed();
			ret->AddLineFeed();


			ret->AddChild( 'z', console_test::Pixel::GetInstance() );
			ret->AddChild( 'x', console_buffer_test::FillBuffer::GetInstance() );
			ret->AddChild( 'c', console_buffer_test::Write2Buffer_WriteConsole::GetInstance() );
			ret->AddChild( 'v', console_buffer_test::Write2Buffer_WriteConsoleOutput::GetInstance() );
			ret->AddChild( 'b', console_buffer_test::DoubleBuffering::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}