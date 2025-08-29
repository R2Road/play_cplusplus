#include "menu_enum.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_enum.hpp"

#include "menu_cpp.hpp"

r2tm::TitleFunctionT EnumMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Enum";
	};
}
r2tm::DescriptionFunctionT EnumMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT EnumMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_cpp_enum::Basic() );
		mp->AddItem( '2', play_cpp_enum::Cast() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_cpp_enum::ConvertWithTemplate() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_cpp_enum::MakeEnumWithMacro() );
		mp->AddItem( 's', play_cpp_enum::XMacro_1() );
		mp->AddItem( 'd', play_cpp_enum::XMacro_2() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_CPP() );
	};
}