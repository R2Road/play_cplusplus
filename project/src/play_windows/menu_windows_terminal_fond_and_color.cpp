#include "menu_windows_terminal_fond_and_color.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_windows_terminal_font.hpp"
#include "play_windows_terminal_text_color.hpp"

#include "menu_windows.hpp"

// # REF
// https://docs.microsoft.com/en-us/windows/console/console-reference


r2tm::TitleFunctionT Menu_Windows_Terminal_Font_And_Color::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Windows Terminal : Font And Text Color";
	};
}
r2tm::DescriptionFunctionT Menu_Windows_Terminal_Font_And_Color::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Windows_Terminal_Font_And_Color::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_windows_terminal_font::FontInfo() );
		mp->AddItem( '2', play_windows_terminal_font::FontChange() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'q', play_windows_terminal_text_color::ColorTable() );
		mp->AddItem( 'w', play_windows_terminal_text_color::TextColor1() );
		mp->AddItem( 'e', play_windows_terminal_text_color::TextColor2() );
		mp->AddItem( 'r', play_windows_terminal_text_color::AdjustColorTable() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'a', play_windows_terminal_text_color::ColorTable2() );
		mp->AddItem( 's', play_windows_terminal_text_color::TextColor3() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Windows() );
	};
}