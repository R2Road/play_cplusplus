#include "NameSpaceMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/cpp_namespace_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp NameSpaceMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', cpp_namespace_test::Basic() );
		ret->AddItem( '2', cpp_namespace_test::Alias() );



		ret->AddSplit();



		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}