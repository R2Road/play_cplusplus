#include "EnumMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/enum_test.h"

#include "C_CPP_Menu.h"

r2cm::MenuUp EnumMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', enum_test::Basic::GetInstance() );
		ret->AddItem( '2', enum_test::Convert::GetInstance() );
		ret->AddItem( '3', enum_test::MakeEnumWithMacro::GetInstance() );
		ret->AddItem( '4', enum_test::XMacro_1::GetInstance() );
		ret->AddItem( '5', enum_test::XMacro_2::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<C_CPP_Menu>( 27 );
	}

	return ret;
}