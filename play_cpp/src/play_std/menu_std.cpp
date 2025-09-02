#include "menu_std.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_algorithm.hpp"
#include "play_std_cout.hpp"
#include "play_std_regex.hpp"
#include "play_std_string.hpp"
#include "play_std_system.hpp"
#include "play_std_tuple.hpp"
#include "play_std_variant.hpp"


#include "menu_root.hpp"
#include "menu_std_cin.hpp"
#include "menu_std_container.hpp"
#include "menu_std_cout.hpp"
#include "menu_std_file_system.hpp"
#include "menu_std_fstream.hpp"
#include "menu_std_functional.hpp"
#include "menu_std_memory.hpp"
#include "menu_std_numeric.hpp"
#include "menu_std_optional.hpp"
#include "menu_std_string.hpp"
#include "menu_std_string_view.hpp"
#include "menu_std_thread.hpp"

r2tm::TitleFunctionT STDMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "STD";
	};
}
r2tm::DescriptionFunctionT STDMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_system::Demo() );
		mp->AddMenu( '2', STDCoutMenu() );
		mp->AddMenu( '3', STDCinMenu() );
		mp->AddMenu( '4', STDFileSystemMenu() );
		mp->AddMenu( '5', STDFstreamMenu() );
		mp->AddMenu( '6', STDOptionalMenu() );
		mp->AddMenu( '7', STDStringMenu() );
		mp->AddMenu( '8', STDStringViewMenu() );



		mp->AddLineFeed();



		mp->AddItem( '8', play_std_tuple::Basic() );
		mp->AddItem( '9', play_std_variant::Basic() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', STDFunctionalMenu() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_std_regex::Basic() );
		mp->AddItem( 's', play_std_algorithm::Shuffle() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', STDMemoryMenu() );
		mp->AddMenu( 'x', STDNumericMenu() );
		mp->AddMenu( 'c', STDContainerMenu() );
		mp->AddMenu( 'v', STDThreadMenu() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}