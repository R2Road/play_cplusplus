#include "menu_serialize.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_serialize.hpp"

#include "menu_hobby.hpp"

r2tm::TitleFunctionT Menu_Serialize::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Serialize";
	};
}
r2tm::DescriptionFunctionT Menu_Serialize::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Serialize::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "...", r2tm::eColor::FG_LightGreen );



		mp->AddLineFeed();



		mp->AddItem( '1', play_serialize::Basic() );
		mp->AddItem( '2', play_serialize::Copy() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Hobby() );
	};
}