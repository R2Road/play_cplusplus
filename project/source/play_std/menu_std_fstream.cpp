#include "menu_std_fstream.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_fstream.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT Menu_STDFstream::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<fstream>";
	};
}
r2tm::DescriptionFunctionT Menu_STDFstream::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_STDFstream::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_fstream::OpenAndClose() );
		mp->AddItem( '2', play_std_fstream::GetCharacter() );
		mp->AddItem( '3', play_std_fstream::GetLine1() );
		mp->AddItem( '4', play_std_fstream::GetLine2() );
		mp->AddItem( '5', play_std_fstream::GetBlank2Blank() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_std_fstream::FileGenerate() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_STD() );
	};
}