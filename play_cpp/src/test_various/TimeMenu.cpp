#include "TimeMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_c/item/c_time_test.h"
#include "test_std/item/std_chrono_test.h"
#include "test_windows/item/windows_time_test.h"

#include "RootMenu.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', c_time_test::Basic() );
		ret->AddItem( '2', c_time_test::Y_M_D_H_M_S_1() );
		ret->AddItem( '3', c_time_test::Y_M_D_H_M_S_2() );
		ret->AddItem( '4', c_time_test::Clock() );



		ret->AddLineFeed();



		ret->AddItem( 'q', window_time_test::Basic() );



		ret->AddLineFeed();



		ret->AddItem( 'a', std_chrono_test::Epoch() );
		ret->AddItem( 's', std_chrono_test::SystemClock() );
		ret->AddItem( 'd', std_chrono_test::SteadyClock() );
		ret->AddItem( 'f', std_chrono_test::SteadyClock_Duration() );
		ret->AddItem( 'g', std_chrono_test::Demo() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}