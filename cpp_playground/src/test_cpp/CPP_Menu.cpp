#include "CPP_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/array_test.h"
#include "item/number_test.h"
#include "item/operator_ternary_test.h"
#include "item/structured_binding_test.h"
#include "item/using_test.h"
#include "test_c/item/c_sizeof_test.h"

#include "AlignMenu.h"
#include "BitOperationMenu.h"
#include "EnumMenu.h"
#include "LambdaMenu.h"
#include "NewMenu.h"
#include "TemplateMenu.h"

#include "ClassMenu.h"
#include "CharMenu.h"
#include "PointerMenu.h"
#include "RootMenu.h"

r2cm::MenuUp CPP_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, CPP_Menu::GetTitle() ) );

	{
		ret->AddMenu<BitOperationMenu>( '1' );
		ret->AddItem( '2', array_test::Init::GetInstance() );
		ret->AddMenu<ClassMenu>( '3' );
		ret->AddItem( '4', c_sizeof_test::Basic::GetInstance() );


		ret->AddLineFeed();


		ret->AddMenu<PointerMenu>( '5' );
		ret->AddMenu<CharMenu>( '6' );
		ret->AddMenu<TemplateMenu>( '7' );
		ret->AddMenu<AlignMenu>( '8' );
		ret->AddMenu<EnumMenu>( '9' );


		ret->AddLineFeed();


		ret->AddMenu<NewMenu>( 'q' );
		ret->AddMenu<LambdaMenu>( 'w' );
		ret->AddItem( 'e', structured_binding_test::Basic::GetInstance() );
		ret->AddItem( 'r', using_test::Basic::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'a', operator_ternary_test::Basic::GetInstance() );
		ret->AddItem( 'b', number_test::Basic::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}