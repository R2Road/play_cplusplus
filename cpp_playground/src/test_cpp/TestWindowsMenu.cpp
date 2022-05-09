#include "pch.h"
#include "TestWindowsMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"

#include "ConsoleTextColorMenu.h"
#include "r2_ConsoleWindowMenu.h"
#include "RootMenu.h"

#include "test_cpp/item/console_buffer_test.h"
#include "test_cpp/item/flickering_research.h"
#include "test_cpp/item/console_input_test.h"
#include "test_cpp/item/console_test.h"
#include "test_cpp/item/console_window_input_test.h"
#include "test_cpp/item/console_window_message_test.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference

r2cm::MenuUp TestWindowsMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem(
			'1'
			, []()->const char* { return r2::ConsoleWindowMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( r2::ConsoleWindowMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
		ret->AddItem(
			'2'
			, []()->const char* { return ConsoleTextColorMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( ConsoleTextColorMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);

		ret->AddLineFeed();
		ret->AddLineFeed();

		ret->AddItem( 'q', console_test::FontInfo::GetInstance() );
		ret->AddItem( 'w', console_test::FontChange::GetInstance() );
		ret->AddItem( 'e', console_window_input_test::WindowInput_ReadConsoleInput::GetInstance() );
		ret->AddItem( 'r', console_window_input_test::WindowInput_GetKeyState::GetInstance() );
		ret->AddItem( 't', console_window_input_test::WindowInput_GetKeyboardState::GetInstance() );
		ret->AddItem( 'y', console_window_input_test::WindowInput_GetAsyncKeyStates::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'u', console_window_message_test::ConsoleControlHandler::GetInstance() );
		ret->AddItem( 'i', console_window_message_test::MessageHook::GetInstance() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'a', console_test::Pixel::GetInstance() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 's', console_buffer_test::FillBuffer::GetInstance() );
		ret->AddItem( 'd', console_buffer_test::Write2Buffer_WriteConsole::GetInstance() );
		ret->AddItem( 'f', console_buffer_test::Write2Buffer_WriteConsoleOutput::GetInstance() );
		ret->AddItem( 'g', console_buffer_test::DoubleBuffering::GetInstance() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'z', flickering_research::OneByOne::GetInstance() );
		ret->AddItem( 'x', flickering_research::OneByOne_WithOut_CLS::GetInstance() );
		ret->AddItem( 'c', flickering_research::LineByLine::GetInstance() );
		ret->AddItem( 'v', flickering_research::PageByPage::GetInstance() );
		ret->AddItem( 'b', flickering_research::PageByPage_WithOut_CLS_1::GetInstance() );
		ret->AddItem( 'n', flickering_research::PageByPage_WithOut_CLS_2::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( RootMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
	}

	return ret;
}