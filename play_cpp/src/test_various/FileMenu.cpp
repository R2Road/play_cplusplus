#include "FileMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_c/item/c_file_test.h"
#include "test_std/item/std_fstream_test.h"

#include "RootMenu.h"

r2tm::TitleFunctionT FileMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "File";
	};
}
r2tm::DescriptionFunctionT FileMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT FileMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', c_file_test::OpenAndClose() );
		ret->AddItem( '2', c_file_test::GetCharacter() );
		ret->AddItem( '3', c_file_test::GetLine() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_fstream_test::OpenAndClose() );
		ret->AddItem( 'w', std_fstream_test::GetCharacter() );
		ret->AddItem( 'e', std_fstream_test::GetLine() );
		ret->AddItem( 'r', std_fstream_test::GetBlank2Blank() );


		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}