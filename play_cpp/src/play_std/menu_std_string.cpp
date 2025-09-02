#include "menu_std_string.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_string.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT Menu_STDString::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<string>";
	};
}
r2tm::DescriptionFunctionT Menu_STDString::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_STDString::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_string::Declaration() );
		mp->AddItem( '2', play_std_string::Operator_Equal() );
		mp->AddItem( '3', play_std_string::Memory_1() );
		mp->AddItem( '4', play_std_string::Memory_2() );
		mp->AddItem( '5', play_std_string::Move() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_std_string::Find_1() );
		mp->AddItem( 'w', play_std_string::Find_2() );
		mp->AddItem( 'e', play_std_string::Find_And_Split_1() );
		mp->AddItem( 'r', play_std_string::Find_And_Split_2() );
		mp->AddItem( 't', play_std_string::Line_Count() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_STD() );
	};
}