#include "EnumMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/enum_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp EnumMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', enum_test::Basic() );
		ret->AddItem( '2', enum_test::Cast() );



		ret->AddLineFeed();



		ret->AddItem( 'q', enum_test::ConvertWithTemplate() );



		ret->AddLineFeed();



		ret->AddItem( 'a', enum_test::MakeEnumWithMacro() );
		ret->AddItem( 's', enum_test::XMacro_1() );
		ret->AddItem( 'd', enum_test::XMacro_2() );


		ret->AddSplit();


		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}