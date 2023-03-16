#include "ETCMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/etc_0_test.h"

#include "RootMenu.h"

r2cm::MenuUp ETCMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', etc_test::ShowBinary() );
		ret->AddItem( '2', etc_test::LifeTimeTest() );
		ret->AddItem( '3', etc_test::STDFunctionImplement() );
		ret->AddItem( '4', etc_test::Braces_PrimitiveType() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}