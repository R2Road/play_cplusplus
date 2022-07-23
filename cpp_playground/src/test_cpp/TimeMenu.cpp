#include "TimeMenu.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Director.h"

#include "test_c/item/c_time_test.h"
#include "test_std/item/std_chrono_test.h"
#include "test_windows/item/windows_time_test.h"

#include "RootMenu.h"

r2cm::MenuUp TimeMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', c_time_test::Basic::GetInstance() );
		ret->AddItem( '2', c_time_test::Y_M_D_H_S::GetInstance() );
		ret->AddItem( '3', c_time_test::Clock::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', window_time_test::Basic::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'w', std_chrono_test::Epoch::GetInstance() );
		ret->AddItem( 'e', std_chrono_test::Chrono::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}