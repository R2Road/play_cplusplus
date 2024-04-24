#include "WindowsTerminalFondAndTextColorMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_windows/item/windows_terminal_font_test.h"
#include "test_windows/item/windows_terminal_text_color_test.h"

#include "test_windows/WindowsMenu.h"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference


r2tm::TitleFunctionT WindowsTerminalFondAndTextColorMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Windows Terminal : Font And Text Color";
	};
}
r2tm::DescriptionFunctionT WindowsTerminalFondAndTextColorMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT WindowsTerminalFondAndTextColorMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', windows_terminal_font_test::FontInfo() );
		ret->AddItem( '2', windows_terminal_font_test::FontChange() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'q', windows_terminal_text_color_test::ColorTable() );
		ret->AddItem( 'w', windows_terminal_text_color_test::TextColor1() );
		ret->AddItem( 'e', windows_terminal_text_color_test::TextColor2() );
		ret->AddItem( 'r', windows_terminal_text_color_test::AdjustColorTable() );


		ret->AddLineFeed();
		ret->AddLineFeed();


		ret->AddItem( 'a', windows_terminal_text_color_test::ColorTable2() );
		ret->AddItem( 's', windows_terminal_text_color_test::TextColor3() );


		ret->AddSplit();


		ret->AddMenu( 27, WindowsMenu() );
	};
}