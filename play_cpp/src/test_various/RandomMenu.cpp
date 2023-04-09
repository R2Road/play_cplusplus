#include "RandomMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_c/item/c_random_test.h"
#include "test_std/item/std_random_test.h"

#include "RootMenu.h"

r2cm::MenuUp RandomMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, RandomMenu::GetTitle() ) );

	{
		ret->AddItem( '1', c_random_test::Rand() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_random_test::Basic() );
		ret->AddItem( 'w', std_random_test::StatusSaveAndLoad() );
		ret->AddItem( 'e', std_random_test::DiscreateDistribution() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}