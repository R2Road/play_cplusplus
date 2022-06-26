#include "ConsoleTextColorMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test_windows/WindowsMenu.h"

#include "test_windows/item/console_text_color_test.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference


r2cm::MenuUp ConsoleTextColorMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', console_text_color_test::ColorTable::GetInstance() );
		ret->AddItem( '2', console_text_color_test::TextColor1::GetInstance() );
		ret->AddItem( '3', console_text_color_test::TextColor2::GetInstance() );
		ret->AddItem( '4', console_text_color_test::AdjustColorTable::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'q', console_text_color_test::ColorTable2::GetInstance() );
		ret->AddItem( 'w', console_text_color_test::TextColor3::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TestWindowsMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}