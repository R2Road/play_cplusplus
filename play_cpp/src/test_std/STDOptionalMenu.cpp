#include "STDOptionalMenu.h"

#include "r2tm/r2tm_Director.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_optional_test::Basic() );
		ret->AddItem( '2', std_optional_test::Constructor() );
		ret->AddItem( '3', std_optional_test::Reference() );


		ret->AddSplit();


		ret->AddMenu( 27, STDMenu() );
	};
}