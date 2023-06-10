#include "UnionMenu.h"

#include "r2tm/r2tm_Director.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', c_union_test::Basic() );
		ret->AddItem( '2', c_union_test::Memory() );
		ret->AddItem( '3', c_union_test::Assign() );
		ret->AddItem( '4', c_union_test::Complex() );



		ret->AddLineFeed();



		ret->AddItem( 'q', c_union_test::Unnamed_Union_With_Struct() );
		ret->AddItem( 'w', c_union_test::Unnamed_Union_With_Vector3() );
		ret->AddItem( 'e', c_union_test::Unnamed_Union_With_Vector3_2() );
		ret->AddItem( 'r', c_union_test::Unnamed_Union_With_Vector3_3() );



		ret->AddSplit();



		ret->AddMenu( 27, C_Menu() );
	};
}