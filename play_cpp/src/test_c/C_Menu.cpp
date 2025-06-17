#include "C_Menu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "item/c_array_test.h"
#include "item/c_atexit_test.h"
#include "item/c_printf_test.h"
#include "item/c_macro_test.h"
#include "item/c_memset_test.h"
#include "item/c_sizeof_test.h"
#include "item/c_struct_test.h"
#include "item/c_system_test.h"
#include "item/c_union_test.h"

#include "BitOperationMenu.h"
#include "C_FileMenu.h"
#include "OperatorMenu.h"
#include "PointerMenu.h"
#include "UnionMenu.h"
#include "menu_root.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', c_array_test::Init() );
		mp->AddMenu( '2', OperatorMenu() );
		mp->AddItem( '3', c_struct_test::ByteAlignment() );
		mp->AddItem( '4', c_struct_test::PragmaPack() );
		mp->AddItem( '5', c_struct_test::Array_Size_0() );
		


		mp->AddLineFeed();


		mp->AddItem( '9', c_printf_test::Basic() );
		mp->AddItem( '0', c_printf_test::ShowNumbers() );


		mp->AddLineFeed();


		mp->AddItem( 'q', c_sizeof_test::Basic() );
		mp->AddItem( 'w', c_memset_test::Basic() );
		mp->AddItem( 'e', c_memset_test::Size() );
		mp->AddItem( 'r', c_macro_test::ToString() );


		mp->AddLineFeed();


		mp->AddMenu( 'a', PointerMenu() );
		mp->AddMenu( 's', BitOperationMenu() );
		mp->AddMenu( 'd', UnionMenu() );
		mp->AddItem( 'f', c_system_test::Pause() );
		mp->AddItem( 'g', c_atexit_test::Basic() );


		mp->AddLineFeed();


		mp->AddMenu( 'z', C_FileMenu() );



		mp->AddSplit();


		mp->AddMenu( 27, RootMenu() );
	};
}