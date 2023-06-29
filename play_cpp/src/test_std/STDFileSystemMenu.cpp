#include "STDFileSystemMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_filesystem_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDFileSystemMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<filesystem>";
	};
}
r2tm::DescriptionFunctionT STDFileSystemMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDFileSystemMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_filesystem_test::DirectoryPath() );
		ret->AddItem( '2', std_filesystem_test::DirectoryIterator() );
		ret->AddItem( '3', std_filesystem_test::RecursiveDirectoryIterator() );
		ret->AddItem( '4', std_filesystem_test::PathOperation_1() );
		ret->AddItem( '5', std_filesystem_test::PathOperation_2() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_filesystem_test::Directory_Check_Make_Delete() );
		ret->AddItem( 'w', std_filesystem_test::Directories_Make() );



		ret->AddLineFeed();



		ret->AddItem( 'a', std_filesystem_test::FileStatus() );



		ret->AddSplit();


		ret->AddMenu( 27, STDMenu() );
	};
}