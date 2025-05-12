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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_numeric_test::Min() );
		mp->AddItem( '2', std_numeric_test::Max() );
		mp->AddItem( '3', std_numeric_test::Accumulate_Number() );
		mp->AddItem( '4', std_numeric_test::Accumulate_String() );
		mp->AddItem( '5', std_numeric_test::Partial_Sum() );
		mp->AddItem( '6', std_numeric_test::FillSequenceNumber() );


		mp->AddSplit();


		mp->AddMenu( 27, STDMenu() );
	};
}