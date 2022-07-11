#include "CharMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_cpp/item/char_test.h"
#include "test_cpp/item/korean_test.h"
#include "test_cpp/item/locale_test.h"

#include "C_CPP_Menu.h"

r2cm::MenuUp CharMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', char_test::Basic::GetInstance() );
		ret->AddItem( '2', char_test::Encoding::GetInstance() );
		ret->AddItem( '3', locale_test::Basic::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'z', korean_test::Basic::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<C_CPP_Menu>( 27 );
	}

	return ret;
}