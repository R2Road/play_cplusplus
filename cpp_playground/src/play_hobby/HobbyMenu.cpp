#include "HobbyMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/infinite_number_test.h"
#include "item/serialize_test.h"

#include "FSM_V1_Menu.h"
#include "ListBasedOnArrayMenu.h"
#include "MemoryPoolMenu.h"
#include "PropertyMenu.h"
#include "TreeMenu.h"
#include "Vector3Menu.h"

#include "RootMenu.h"

r2cm::MenuUp HobbyMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddMenu<FSM_V1_Menu>( '1' );
		ret->AddMenu<TreeMenu>( '4' );


		ret->AddLineFeed();


		ret->AddMenu<PropertyMenu>( '5' );
		ret->AddItem( '6', serialize_test::Basic() );
		ret->AddItem( '7', serialize_test::Copy() );


		ret->AddSplit();


		ret->AddMenu<MemoryPoolMenu>( 'q' );
		ret->AddItem( 'w', infinite_number_test::Basic() );


		ret->AddSplit();


		ret->AddMenu<Vector3Menu>( 'a' );


		ret->AddSplit();


		ret->AddMenu<ListBasedOnArrayMenu>( 'z' );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}