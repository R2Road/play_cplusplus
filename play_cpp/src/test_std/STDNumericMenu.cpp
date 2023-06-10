#include "STDNumericMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_numeric_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDNumericMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<numeric>";
	};
}
r2tm::DescriptionFunctionT STDNumericMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDNumericMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_numeric_test::Accumulate_Number() );
		ret->AddItem( '2', std_numeric_test::Accumulate_String() );
		ret->AddItem( '3', std_numeric_test::Partial_Sum() );
		ret->AddItem( '4', std_numeric_test::FillSequenceNumber() );


		ret->AddSplit();


		ret->AddMenu( 27, STDMenu() );
	};
}