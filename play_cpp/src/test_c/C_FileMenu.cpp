#include "C_FileMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_c/item/c_file_test.h"

#include "C_Menu.h"

r2tm::TitleFunctionT C_FileMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "File";
	};
}
r2tm::DescriptionFunctionT C_FileMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT C_FileMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', c_file_test::OpenAndClose() );
		mp->AddItem( '2', c_file_test::GetCharacter() );
		mp->AddItem( '3', c_file_test::GetLine() );
		mp->AddItem( '4', c_file_test::GetFormat() );



		mp->AddLineFeed();



		mp->AddItem( 'q', c_file_test::FileGenerate() );



		mp->AddSplit();



		mp->AddMenu( 27, C_Menu() );
	};
}