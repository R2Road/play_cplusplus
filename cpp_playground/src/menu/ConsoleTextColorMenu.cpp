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
		ret->AddChild( 'q', console_text_color_test::ColorTable::GetInstance() );
		ret->AddChild( 'w', console_text_color_test::TextColor1::GetInstance() );
		ret->AddChild( 'e', console_text_color_test::TextColor2::GetInstance() );
		ret->AddChild( 'r', console_text_color_test::AdjustColorTable::GetInstance() );

		ret->AddLineFeed();

		ret->AddChild( 't', console_text_color_test::ColorTable2::GetInstance() );
		ret->AddChild( 'y', console_text_color_test::TextColor3::GetInstance() );


		ret->AddSplit();


		ret->AddChild(
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