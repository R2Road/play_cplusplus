#include "menu_c_file.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c_file.hpp"

#include "menu_c.hpp"

r2tm::TitleFunctionT Menu_C_File::GetTitleFunction() const
{
	return []()->const char*
	{
		return "File";
	};
}
r2tm::DescriptionFunctionT Menu_C_File::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_C_File::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_c_file::OpenAndClose() );
		mp->AddItem( '2', play_c_file::GetCharacter() );
		mp->AddItem( '3', play_c_file::GetLine() );
		mp->AddItem( '4', play_c_file::GetFormat() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_c_file::FileGenerate() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_C() );
	};
}