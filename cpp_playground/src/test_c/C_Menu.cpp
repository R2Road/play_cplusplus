#include "C_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

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
#include "RootMenu.h"

r2cm::MenuUp C_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, C_Menu::GetTitle() ) );

	{
		ret->AddItem( '1', c_array_test::Init::GetInstance() );
		ret->AddItem( '2', c_operator_ternary_test::Basic::GetInstance() );
		ret->AddItem( '3', c_operator_ternary_test::Comma::GetInstance() );
		ret->AddItem( '4', c_struct_test::Array_Size_0::GetInstance() );
		ret->AddItem( '5', c_union_test::Basic::GetInstance() );
		ret->AddItem( '6', c_union_test::Unnamed_Union_With_Struct::GetInstance() );
		ret->AddItem( '7', c_union_test::Unnamed_Union_With_Vector3::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( '8', c_printf_test::Basic::GetInstance() );
		ret->AddItem( '9', c_printf_test::ShowNumbers::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', c_sizeof_test::Basic::GetInstance() );
		ret->AddItem( 'w', c_memset_test::Basic::GetInstance() );
		ret->AddItem( 'e', c_macro_test::ToString::GetInstance() );


		ret->AddLineFeed();


		ret->AddMenu<PointerMenu>( 'a' );
		ret->AddMenu<BitOperationMenu>( 's' );
		ret->AddItem( 'd', c_system_test::Pause::GetInstance() );
		ret->AddItem( 'f', c_atexit_test::Basic::GetInstance() );



		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}