#include "HobbyMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/infinite_number_test.h"
#include "item/serialize_test.h"
#include "item/spin_lock_play.h"

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
		ret->AddItem( '1', spin_lock_play::Basic() );



		ret->AddLineFeed();



		ret->AddMenu<TreeMenu>( 'q' );
		ret->AddMenu<PropertyMenu>( 'w' );



		ret->AddLineFeed();



		ret->AddMenu<FSM_V1_Menu>( 'a' );
		ret->AddItem( 's', serialize_test::Basic() );
		ret->AddItem( 'd', serialize_test::Copy() );
		ret->AddItem( 'f', infinite_number_test::Basic() );



		ret->AddLineFeed();



		ret->AddMenu<ListBasedOnArrayMenu>( 'z' );
		ret->AddMenu<Vector3Menu>( 'x' );
		ret->AddMenu<MemoryPoolMenu>( 'c' );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}