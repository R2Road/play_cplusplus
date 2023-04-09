#include "UnionMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/c_union_test.h"

#include "C_Menu.h"

r2cm::MenuUp UnionMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, UnionMenu::GetTitle() ) );

	{
		ret->AddItem( '1', c_union_test::Basic() );
		ret->AddItem( '2', c_union_test::Memory() );
		ret->AddItem( '3', c_union_test::Assign() );
		ret->AddItem( '4', c_union_test::Complex() );



		ret->AddLineFeed();



		ret->AddItem( 'q', c_union_test::Unnamed_Union_With_Struct() );
		ret->AddItem( 'w', c_union_test::Unnamed_Union_With_Vector3() );
		ret->AddItem( 'e', c_union_test::Unnamed_Union_With_Vector3_2() );
		ret->AddItem( 'r', c_union_test::Unnamed_Union_With_Vector3_3() );



		ret->AddSplit();



		ret->AddMenu<C_Menu>( 27 );
	}

	return ret;
}