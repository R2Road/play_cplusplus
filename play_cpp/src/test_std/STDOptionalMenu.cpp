#include "STDOptionalMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_std/item/std_optional_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDOptionalMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_optional_test::Basic() );
		ret->AddItem( '2', std_optional_test::Constructor() );
		ret->AddItem( '3', std_optional_test::Reference() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}