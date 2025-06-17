#include "TimeMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_c/item/c_time_test.h"
#include "test_std/item/std_chrono_test.h"
#include "test_windows/item/windows_time_test.h"

#include "menu_root.h"

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
		mp->AddItem( '1', c_time_test::Basic() );
		mp->AddItem( '2', c_time_test::Y_M_D_H_M_S_1() );
		mp->AddItem( '3', c_time_test::Y_M_D_H_M_S_2() );
		mp->AddItem( '4', c_time_test::Clock() );



		mp->AddLineFeed();



		mp->AddItem( 'q', window_time_test::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'a', std_chrono_test::Epoch() );
		mp->AddItem( 's', std_chrono_test::SystemClock() );
		mp->AddItem( 'd', std_chrono_test::SteadyClock() );
		mp->AddItem( 'f', std_chrono_test::SteadyClock_Duration() );
		mp->AddItem( 'g', std_chrono_test::Demo() );



		mp->AddSplit();



		mp->AddMenu( 27, RootMenu() );
	};
}