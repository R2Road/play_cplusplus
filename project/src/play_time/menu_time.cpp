#include "menu_time.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c/play_c_time.hpp"
#include "play_std/play_std_chrono.hpp"
#include "test_windows/item/windows_time_test.h"

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_Time::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Time";
	};
}
r2tm::DescriptionFunctionT Menu_Time::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Time::GetWriteFunction() const
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



		mp->AddItem( 'a', play_std_chrono::Epoch() );
		mp->AddItem( 's', play_std_chrono::SystemClock() );
		mp->AddItem( 'd', play_std_chrono::SteadyClock() );
		mp->AddItem( 'f', play_std_chrono::SteadyClock_Duration() );
		mp->AddItem( 'g', play_std_chrono::Demo() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}