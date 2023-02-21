#include "ConsoleTextColorMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_windows/item/windows_terminal_text_color_test.h"

#include "test_windows/WindowsMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference


r2cm::MenuUp ConsoleTextColorMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', windows_terminal_text_color_test::ColorTable() );
		ret->AddItem( '2', windows_terminal_text_color_test::TextColor1() );
		ret->AddItem( '3', windows_terminal_text_color_test::TextColor2() );
		ret->AddItem( '4', windows_terminal_text_color_test::AdjustColorTable() );


		ret->AddLineFeed();


		ret->AddItem( 'q', windows_terminal_text_color_test::ColorTable2() );
		ret->AddItem( 'w', windows_terminal_text_color_test::TextColor3() );


		ret->AddSplit();


		ret->AddMenu<WindowsMenu>( 27 );
	}

	return ret;
}