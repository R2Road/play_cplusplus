#include "TimeMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c/play_c_time.hpp"
#include "test_std/item/std_chrono_test.h"
#include "test_windows/item/windows_time_test.h"

#include "menu_root.hpp"

r2tm::TitleFunctionT TimeMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Time";
	};
}
r2tm::DescriptionFunctionT TimeMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT TimeMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_c_time::Basic() );
		mp->AddItem( '2', play_c_time::Y_M_D_H_M_S_1() );
		mp->AddItem( '3', play_c_time::Y_M_D_H_M_S_2() );
		mp->AddItem( '4', play_c_time::Clock() );



		mp->AddLineFeed();



		mp->AddItem( 'q', window_time_test::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'a', std_chrono_test::Epoch() );
		mp->AddItem( 's', std_chrono_test::SystemClock() );
		mp->AddItem( 'd', std_chrono_test::SteadyClock() );
		mp->AddItem( 'f', std_chrono_test::SteadyClock_Duration() );
		mp->AddItem( 'g', std_chrono_test::Demo() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}