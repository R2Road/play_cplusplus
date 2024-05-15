#include "STDCinMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_cin_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDCinMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "std::cin";
	};
}
r2tm::DescriptionFunctionT STDCinMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDCinMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_cin_test::InputLimit() );



		ret->AddSplit();



		ret->AddMenu( 27, STDMenu() );
	};
}