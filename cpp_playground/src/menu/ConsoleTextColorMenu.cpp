#include "pch.h"
#include "ConsoleTextColorMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"

#include "r2_ConsoleMenu.h"

#include "test_cpp/console_text_color_test.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference


r2::MenuUp ConsoleTextColorMenu::Create( r2::Director& director )
{
	r2::MenuUp ret( new ( std::nothrow ) r2::Menu( director, GetTitle() ) );

	{
		ret->AddItem( 'q', console_text_color_test::ColorTable::GetInstance() );
		ret->AddItem( 'w', console_text_color_test::TextColor1::GetInstance() );
		ret->AddItem( 'e', console_text_color_test::TextColor2::GetInstance() );
		ret->AddItem( 'r', console_text_color_test::AdjustColorTable::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 't', console_text_color_test::ColorTable2::GetInstance() );
		ret->AddItem( 'y', console_text_color_test::TextColor3::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2::eTestEndAction
			{
				director.Setup( r2::ConsoleMenu::Create( director ) );
				return r2::eTestEndAction::None;
			}
		);
	}

	return ret;
}