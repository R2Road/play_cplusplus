#include "HobbyMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_hobby/item/fsm_v1_test.h"
#include "test_hobby/item/infinite_number_test.h"

#include "ArrayBasedListMenu.h"
#include "MemoryPoolMenu.h"
#include "Vector3Menu.h"

#include "RootMenu.h"

r2cm::MenuUp HobbyMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddMenu<MemoryPoolMenu>( '1' );


		ret->AddSplit();


		ret->AddItem( 'q', infinite_number_test::Basic::GetInstance() );
		ret->AddItem( 'w', fsm_v1_test::Basic::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<Vector3Menu>( 'a' );


		ret->AddSplit();


		ret->AddMenu<ArrayBasedListMenu>( 'z' );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}