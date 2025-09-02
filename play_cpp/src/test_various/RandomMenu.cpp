#include "RandomMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c/play_c_random.hpp"
#include "play_std/play_std_random.hpp"

#include "menu_root.hpp"

r2tm::TitleFunctionT RandomMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Random";
	};
}
r2tm::DescriptionFunctionT RandomMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT RandomMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_c_random::Rand() );


		mp->AddLineFeed();


		mp->AddItem( 'q', play_std_random::Basic() );
		mp->AddItem( 'w', play_std_random::StatusSaveAndLoad() );
		mp->AddItem( 'e', play_std_random::DiscreateDistribution() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}