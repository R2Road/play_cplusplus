#include "ETCMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/etc_0_test.h"

#include "RootMenu.h"

r2cm::MenuUp ETCMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', etc_test::ShowBinary::GetInstance() );
		ret->AddItem( '2', etc_test::LifeTimeTest::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}