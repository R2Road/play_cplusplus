#include "NewMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/cpp_new_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp NewMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', cpp_new_test::Basic() );
		ret->AddItem( '2', cpp_new_test::Array() );
		ret->AddItem( '3', cpp_new_test::PlacementNew() );



		ret->AddSplit();



		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}