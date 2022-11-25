#include "UnionMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/c_union_test.h"

#include "C_Menu.h"

r2cm::MenuUp UnionMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, UnionMenu::GetTitle() ) );

	{
		ret->AddItem( '1', c_union_test::Basic::GetInstance() );
		ret->AddItem( '2', c_union_test::Unnamed_Union_With_Struct::GetInstance() );
		ret->AddItem( '3', c_union_test::Unnamed_Union_With_Vector3::GetInstance() );
		ret->AddItem( '4', c_union_test::Unnamed_Union_With_Vector3_2::GetInstance() );



		ret->AddSplit();



		ret->AddMenu<C_Menu>( 27 );
	}

	return ret;
}