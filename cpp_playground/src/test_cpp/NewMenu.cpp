#include "NewMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/new_test.h"

#include "C_CPP_Menu.h"

r2cm::MenuUp NewMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', new_test::Basic::GetInstance() );
		ret->AddItem( '2', new_test::PlacementNew::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<C_CPP_Menu>( 27 );
	}

	return ret;
}