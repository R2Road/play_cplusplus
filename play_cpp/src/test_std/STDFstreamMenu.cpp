#include "STDFstreamMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_fstream_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDFstreamMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<fstream>";
	};
}
r2tm::DescriptionFunctionT STDFstreamMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDFstreamMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_fstream_test::OpenAndClose() );
		ret->AddItem( '2', std_fstream_test::GetCharacter() );
		ret->AddItem( '3', std_fstream_test::GetLine() );
		ret->AddItem( '4', std_fstream_test::GetBlank2Blank() );



		ret->AddSplit();



		ret->AddMenu( 27, STDMenu() );
	};
}