#include "menu_windows_terminal_flickering_research.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_windows_terminal_flickering_research.hpp"

#include "menu_windows.hpp"

r2tm::TitleFunctionT Menu_Windows_Terminal_Flickering_Research::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Flickering Research";
	};
}
r2tm::DescriptionFunctionT Menu_Windows_Terminal_Flickering_Research::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Windows_Terminal_Flickering_Research::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_windows_terminal_flickering_research::OneByOne() );
		mp->AddItem( '2', play_windows_terminal_flickering_research::OneByOne_WithOut_CLS() );
		mp->AddItem( '3', play_windows_terminal_flickering_research::LineByLine() );
		mp->AddItem( '4', play_windows_terminal_flickering_research::PageByPage() );
		mp->AddItem( '5', play_windows_terminal_flickering_research::PageByPage_WithOut_CLS_1() );
		mp->AddItem( '6', play_windows_terminal_flickering_research::PageByPage_WithOut_CLS_2() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Windows() );
	};
}