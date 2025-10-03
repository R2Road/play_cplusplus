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

r2tm::TitleFunctionT Menu_STD::GetTitleFunction() const
{
	return []()->const char*
	{
		return "STD";
	};
}
r2tm::DescriptionFunctionT Menu_STD::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_STD::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_system::Demo() );
		mp->AddMenu( '2', Menu_STDCout() );
		mp->AddMenu( '3', Menu_STDCin() );
		mp->AddMenu( '4', Menu_STDFileSystem() );
		mp->AddMenu( '5', Menu_STDFstream() );
		mp->AddMenu( '6', Menu_STDOptional() );
		mp->AddMenu( '7', Menu_STDString() );
		mp->AddMenu( '8', Menu_STDStringView() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_std_tuple::Basic() );
		mp->AddItem( 'w', play_std_variant::Basic() );
		mp->AddMenu( 'e', Menu_STDFunctional() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_std_regex::Basic() );
		mp->AddItem( 's', play_std_algorithm::Shuffle() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', Menu_STDMemory() );
		mp->AddMenu( 'x', Menu_STDNumeric() );
		mp->AddMenu( 'c', Menu_STDContainer() );
		mp->AddMenu( 'v', Menu_STDThread() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}