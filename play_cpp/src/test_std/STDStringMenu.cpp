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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_string_test::Declaration() );
		ret->AddItem( '2', std_string_test::Operator_Equal() );
		ret->AddItem( '3', std_string_test::Memory_1() );
		ret->AddItem( '4', std_string_test::Memory_2() );
		ret->AddItem( '5', std_string_test::Move() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_string_test::Find_1() );
		ret->AddItem( 'w', std_string_test::Find_2() );
		ret->AddItem( 'e', std_string_test::Find_And_Split_1() );
		ret->AddItem( 'r', std_string_test::Find_And_Split_2() );
		ret->AddItem( 't', std_string_test::Line_Count() );



		ret->AddSplit();



		ret->AddMenu( 27, STDMenu() );
	};
}