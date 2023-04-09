#include "C_Menu.h"

#include "r2cm/r2cm_Director.h"

#include "item/c_array_test.h"
#include "item/c_atexit_test.h"
#include "item/c_operator_ternary_test.h"
#include "item/c_printf_test.h"
#include "item/c_macro_test.h"
#include "item/c_memset_test.h"
#include "item/c_sizeof_test.h"
#include "item/c_struct_test.h"
#include "item/c_system_test.h"
#include "item/c_union_test.h"

#include "BitOperationMenu.h"
#include "PointerMenu.h"
#include "UnionMenu.h"
#include "RootMenu.h"

r2cm::MenuUp C_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_Menu::GetTitle() ) );

	{
		ret->AddItem( '1', c_array_test::Init() );
		ret->AddItem( '2', c_operator_ternary_test::Basic() );
		ret->AddItem( '3', c_operator_ternary_test::Comma() );
		ret->AddItem( '4', c_operator_ternary_test::Void() );
		ret->AddItem( '5', c_struct_test::ByteAlignment() );
		ret->AddItem( '6', c_struct_test::PragmaPack() );
		ret->AddItem( '7', c_struct_test::Array_Size_0() );
		


		ret->AddLineFeed();


		ret->AddItem( '9', c_printf_test::Basic() );
		ret->AddItem( '0', c_printf_test::ShowNumbers() );


		ret->AddLineFeed();


		ret->AddItem( 'q', c_sizeof_test::Basic() );
		ret->AddItem( 'w', c_memset_test::Basic() );
		ret->AddItem( 'e', c_macro_test::ToString() );


		ret->AddLineFeed();


		ret->AddMenu<PointerMenu>( 'a' );
		ret->AddMenu<BitOperationMenu>( 's' );
		ret->AddMenu<UnionMenu>( 'd' );
		ret->AddItem( 'f', c_system_test::Pause() );
		ret->AddItem( 'g', c_atexit_test::Basic() );



		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}