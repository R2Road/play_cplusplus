#include "menu_std_align.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_memory_align.hpp"

#include "menu_std_memory.hpp"

r2tm::TitleFunctionT STDAlignMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "STDAlign";
	};
}
r2tm::DescriptionFunctionT STDAlignMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDAlignMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_memory_align::Basic() );
		mp->AddItem( '2', play_std_memory_align::Bound() );
		mp->AddItem( '3', play_std_memory_align::Play() );


		mp->AddSplit();


		mp->AddMenu( 27, STDMemoryMenu() );
	};
}