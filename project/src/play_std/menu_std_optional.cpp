#include "menu_std_optional.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_optional.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT Menu_STDOptional::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<optional>";
	};
}
r2tm::DescriptionFunctionT Menu_STDOptional::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_STDOptional::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_optional::Basic() );
		mp->AddItem( '2', play_std_optional::Constructor() );
		mp->AddItem( '3', play_std_optional::Reference() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_STD() );
	};
}