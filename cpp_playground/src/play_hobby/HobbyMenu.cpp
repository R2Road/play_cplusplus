#include "HobbyMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/play_infinite_number.h"
#include "item/play_serialize.h"
#include "item/play_spin_lock.h"

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
		ret->AddItem( '1', play_spin_lock::Basic() );



		ret->AddLineFeed();



		ret->AddMenu<TreeMenu>( 'q' );
		ret->AddMenu<PropertyMenu>( 'w' );



		ret->AddLineFeed();



		ret->AddMenu<FSM_V1_Menu>( 'a' );
		ret->AddItem( 's', play_serialize::Basic() );
		ret->AddItem( 'd', play_serialize::Copy() );
		ret->AddItem( 'f', play_infinite_number::Basic() );



		ret->AddLineFeed();



		ret->AddMenu<ListBasedOnArrayMenu>( 'z' );
		ret->AddMenu<Vector3Menu>( 'x' );
		ret->AddMenu<MemoryPoolMenu>( 'c' );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}