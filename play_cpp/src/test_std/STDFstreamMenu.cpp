#include "STDFstreamMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_fstream_test::OpenAndClose() );
		mp->AddItem( '2', std_fstream_test::GetCharacter() );
		mp->AddItem( '3', std_fstream_test::GetLine1() );
		mp->AddItem( '4', std_fstream_test::GetLine2() );
		mp->AddItem( '5', std_fstream_test::GetBlank2Blank() );



		mp->AddLineFeed();



		mp->AddItem( 'q', std_fstream_test::FileGenerate() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}