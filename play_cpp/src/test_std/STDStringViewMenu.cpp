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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_string_view_test::Basic() );
		ret->AddItem( '2', std_string_view_test::Literal_Operator_sv() );
		ret->AddItem( '3', std_string_view_test::Remove() );
		ret->AddItem( '4', std_string_view_test::SubStr() );



		ret->AddSplit();



		ret->AddMenu( 27, STDMenu() );
	};
}