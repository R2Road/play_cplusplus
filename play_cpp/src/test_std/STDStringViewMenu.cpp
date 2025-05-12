#include "STDStringViewMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_string_view_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDStringViewMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<string_view>";
	};
}
r2tm::DescriptionFunctionT STDStringViewMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDStringViewMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_string_view_test::Declaration() );
		mp->AddItem( '2', std_string_view_test::Iteration() );
		mp->AddItem( '3', std_string_view_test::Literal_Operator_sv() );
		mp->AddItem( '4', std_string_view_test::Remove() );
		mp->AddItem( '5', std_string_view_test::SubStr() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}