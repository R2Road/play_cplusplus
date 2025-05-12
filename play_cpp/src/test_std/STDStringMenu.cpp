#include "STDStringMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_string_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDStringMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<string>";
	};
}
r2tm::DescriptionFunctionT STDStringMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDStringMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_string_test::Declaration() );
		mp->AddItem( '2', std_string_test::Operator_Equal() );
		mp->AddItem( '3', std_string_test::Memory_1() );
		mp->AddItem( '4', std_string_test::Memory_2() );
		mp->AddItem( '5', std_string_test::Move() );



		mp->AddLineFeed();



		mp->AddItem( 'q', std_string_test::Find_1() );
		mp->AddItem( 'w', std_string_test::Find_2() );
		mp->AddItem( 'e', std_string_test::Find_And_Split_1() );
		mp->AddItem( 'r', std_string_test::Find_And_Split_2() );
		mp->AddItem( 't', std_string_test::Line_Count() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}