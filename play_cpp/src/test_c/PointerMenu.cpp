#include "PointerMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/c_pointer_test.h"

#include "C_Menu.h"

r2cm::MenuUp PointerMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, PointerMenu::GetTitle() ) );

	{
		ret->AddItem( '1', c_pointer_test::Basic() );
		ret->AddItem( '2', c_pointer_test::Offset() );
		ret->AddItem( '3', c_pointer_test::Pointer2Index() );
		ret->AddItem( '4', c_pointer_test::ConstPointer() );



		ret->AddLineFeed();



		ret->AddItem( 'q', c_pointer_test::CharacterPointer_Length_0() );



		ret->AddSplit();


		ret->AddMenu<C_Menu>( 27 );
	}

	return ret;
}