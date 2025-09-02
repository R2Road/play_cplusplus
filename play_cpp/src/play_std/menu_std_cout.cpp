#include "menu_std_cout.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_cout.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT STDCoutMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "std::cout";
	};
}
r2tm::DescriptionFunctionT STDCoutMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDCoutMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_cout::Basic() );
		mp->AddItem( '2', play_std_cout::FMTStatus() );
		mp->AddItem( '3', play_std_cout::NumberFormat_1() );
		mp->AddItem( '4', play_std_cout::NumberFormat_2() );
		mp->AddItem( '5', play_std_cout::NumberFormat_3() );
		mp->AddItem( '6', play_std_cout::NumberFormat_4() );


		mp->AddLineFeed();


		mp->AddItem( 'q', play_std_cout::Align() );
		mp->AddItem( 'w', play_std_cout::Flag() );
		mp->AddItem( 'e', play_std_cout::BoolAlpha() );


		mp->AddLineFeed();


		mp->AddItem( 'a', play_std_cout::UserDefinedType() );


		mp->AddSplit();


		mp->AddMenu( 27, STDMenu() );
	};
}