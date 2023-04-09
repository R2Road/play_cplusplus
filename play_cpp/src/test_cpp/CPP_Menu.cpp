#include "CPP_Menu.h"

#include "r2cm/r2cm_Director.h"

#include "item/cpp_structured_binding_test.h"
#include "item/number_test.h"
#include "item/using_test.h"

#include "AlignMenu.h"
#include "EnumMenu.h"
#include "LambdaMenu.h"
#include "NameSpaceMenu.h"
#include "NewMenu.h"

#include "ClassMenu.h"
#include "CharMenu.h"
#include "RootMenu.h"

r2cm::MenuUp CPP_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, CPP_Menu::GetTitle() ) );

	{
		ret->AddMenu<ClassMenu>( '1' );
		ret->AddMenu<NameSpaceMenu>( '2' );


		ret->AddLineFeed();


		ret->AddMenu<CharMenu>( '6' );
		ret->AddMenu<AlignMenu>( '7' );
		ret->AddMenu<EnumMenu>( '8' );


		ret->AddLineFeed();


		ret->AddMenu<NewMenu>( 'q' );
		ret->AddMenu<LambdaMenu>( 'w' );
		ret->AddItem( 'e', using_test::Basic() );


		ret->AddLineFeed();


		ret->AddItem( 'a', cpp_structured_binding_test::Basic() );
		ret->AddItem( 'b', number_test::Prefix() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}