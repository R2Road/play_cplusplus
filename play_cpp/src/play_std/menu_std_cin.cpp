#include "menu_std_cin.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_cin.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT STDCinMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "std::cin";
	};
}
r2tm::DescriptionFunctionT STDCinMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDCinMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_cin::InputLimit() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}