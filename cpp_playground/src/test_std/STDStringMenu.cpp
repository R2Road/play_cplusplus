#include "STDStringMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_std/item/std_string_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDStringMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_string_test::Basic() );
		ret->AddItem( '2', std_string_test::Move() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_string_test::Find() );
		ret->AddItem( 'w', std_string_test::Find_And_Split_1() );
		ret->AddItem( 'e', std_string_test::Find_And_Split_2() );
		ret->AddItem( 'r', std_string_test::Line_Count() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}