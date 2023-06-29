#include "C_Menu.h"

#include "r2tm/r2tm_Director.h"

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
#include "C_FileMenu.h"
#include "PointerMenu.h"
#include "UnionMenu.h"
#include "RootMenu.h"

r2tm::TitleFunctionT C_Menu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "C";
	};
}
r2tm::DescriptionFunctionT C_Menu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT C_Menu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
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


		ret->AddMenu( 'a', PointerMenu() );
		ret->AddMenu( 's', BitOperationMenu() );
		ret->AddMenu( 'd', UnionMenu() );
		ret->AddItem( 'f', c_system_test::Pause() );
		ret->AddItem( 'g', c_atexit_test::Basic() );


		ret->AddLineFeed();


		ret->AddMenu( 'z', C_FileMenu() );



		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}