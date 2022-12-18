#include "STDCoutMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_std/item/std_cout_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDCoutMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_cout_test::Basic() );
		ret->AddItem( '2', std_cout_test::FMTStatus() );
		ret->AddItem( '3', std_cout_test::NumberFormat_1() );
		ret->AddItem( '4', std_cout_test::NumberFormat_2() );
		ret->AddItem( '5', std_cout_test::NumberFormat_3() );
		ret->AddItem( '6', std_cout_test::NumberFormat_4() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_cout_test::Align() );
		ret->AddItem( 'w', std_cout_test::Flag() );
		ret->AddItem( 'e', std_cout_test::BoolAlpha() );


		ret->AddLineFeed();


		ret->AddItem( 'a', std_cout_test::UserDefinedType() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}