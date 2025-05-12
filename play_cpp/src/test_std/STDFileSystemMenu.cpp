#include "STDFileSystemMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_filesystem_test::DirectoryPath() );
		mp->AddItem( '2', std_filesystem_test::DirectoryIterator() );
		mp->AddItem( '3', std_filesystem_test::RecursiveDirectoryIterator() );



		mp->AddLineFeed();



		mp->AddItem( 'q', std_filesystem_test::PathOperation_1() );
		mp->AddItem( 'w', std_filesystem_test::PathOperation_2() );
		mp->AddItem( 'e', std_filesystem_test::PathOperation_3() );
		mp->AddItem( 'r', std_filesystem_test::PathOperation_4() );



		mp->AddLineFeed();



		mp->AddItem( 'a', std_filesystem_test::Exist() );
		mp->AddItem( 's', std_filesystem_test::Directory_Make_Delete() );
		mp->AddItem( 'd', std_filesystem_test::Directories_Make() );



		mp->AddLineFeed();



		mp->AddItem( 'z', std_filesystem_test::FileStatus() );



		mp->AddSplit();


		mp->AddMenu( 27, STDMenu() );
	};
}