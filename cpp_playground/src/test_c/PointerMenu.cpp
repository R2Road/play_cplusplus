#include "PointerMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/pointer_test.h"

#include "C_Menu.h"

r2cm::MenuUp PointerMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, PointerMenu::GetTitle() ) );

	{
		ret->AddItem( '1', pointer_test::Basic::GetInstance() );
		ret->AddItem( '2', pointer_test::Offset::GetInstance() );
		ret->AddItem( '3', pointer_test::Pointer2Index::GetInstance() );
		ret->AddItem( '4', pointer_test::ConstPointer::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<C_Menu>( 27 );
	}

	return ret;
}