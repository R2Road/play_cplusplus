#include "CharMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_cpp/item/char_test.h"
#include "test_cpp/item/korean_test.h"
#include "test_cpp/item/locale_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp CharMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', char_test::Basic() );
		ret->AddItem( '2', char_test::Encoding() );
		ret->AddItem( '3', locale_test::Basic() );
		ret->AddItem( '4', char_test::RawStringLiteral() );


		ret->AddLineFeed();


		ret->AddItem( 'z', korean_test::Basic() );


		ret->AddSplit();


		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}