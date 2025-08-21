#include "UnionMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "item/c_union_test.h"

#include "C_Menu.h"

r2tm::TitleFunctionT UnionMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Union";
	};
}
r2tm::DescriptionFunctionT UnionMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT UnionMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', c_union_test::Basic() );
		mp->AddItem( '2', c_union_test::Memory() );
		mp->AddItem( '3', c_union_test::Assign() );
		mp->AddItem( '4', c_union_test::Complex() );



		mp->AddLineFeed();



		mp->AddItem( 'q', c_union_test::Unnamed_Union_With_Struct() );
		mp->AddItem( 'w', c_union_test::Unnamed_Union_With_Vector3() );
		mp->AddItem( 'e', c_union_test::Unnamed_Union_With_Vector3_2() );
		mp->AddItem( 'r', c_union_test::Unnamed_Union_With_Vector3_3() );
		mp->AddItem( 't', c_union_test::Unnamed_Union_With_Vector3_4() );
		mp->AddItem( 'y', c_union_test::Unnamed_Union_With_Vector3_5() );



		mp->AddSplit();



		mp->AddMenu( 27, C_Menu() );
	};
}