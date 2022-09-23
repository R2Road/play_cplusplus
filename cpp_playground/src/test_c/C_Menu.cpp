#include "C_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/c_array_test.h"
#include "item/c_printf_test.h"
#include "item/c_memset_test.h"
#include "item/c_sizeof_test.h"

#include "PointerMenu.h"
#include "RootMenu.h"

r2cm::MenuUp C_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_Menu::GetTitle() ) );

	{
		ret->AddItem( '1', c_array_test::Init::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( '2', c_printf_test::Basic::GetInstance() );
		ret->AddItem( '3', c_printf_test::ShowNumbers::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', c_sizeof_test::Basic::GetInstance() );
		ret->AddItem( 'w', c_memset_test::Basic::GetInstance() );


		ret->AddLineFeed();


		ret->AddMenu<PointerMenu>( 'a' );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}