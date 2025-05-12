#include "STDOptionalMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_std/item/std_optional_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDOptionalMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<optional>";
	};
}
r2tm::DescriptionFunctionT STDOptionalMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDOptionalMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_optional_test::Basic() );
		mp->AddItem( '2', std_optional_test::Constructor() );
		mp->AddItem( '3', std_optional_test::Reference() );


		mp->AddSplit();


		mp->AddMenu( 27, STDMenu() );
	};
}