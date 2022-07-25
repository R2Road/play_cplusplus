#include "C_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/c_printf_test.h"
#include "item/c_sizeof_test.h"

#include "RootMenu.h"

r2cm::MenuUp C_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_Menu::GetTitle() ) );

	{
		ret->AddItem( '1', print_test::Basic::GetInstance() );
		ret->AddItem( '2', print_test::ShowNumbers::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', c_sizeof_test::Basic::GetInstance() );


		ret->AddLineFeed();


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}