#include "WindowsTerminalFondAndTextColorMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', windows_terminal_font_test::FontInfo() );
		mp->AddItem( '2', windows_terminal_font_test::FontChange() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'q', windows_terminal_text_color_test::ColorTable() );
		mp->AddItem( 'w', windows_terminal_text_color_test::TextColor1() );
		mp->AddItem( 'e', windows_terminal_text_color_test::TextColor2() );
		mp->AddItem( 'r', windows_terminal_text_color_test::AdjustColorTable() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'a', windows_terminal_text_color_test::ColorTable2() );
		mp->AddItem( 's', windows_terminal_text_color_test::TextColor3() );


		mp->AddSplit();


		mp->AddMenu( 27, WindowsMenu() );
	};
}