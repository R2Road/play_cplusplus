#include "STDFileSystemMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_std/item/std_filesystem_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDFileSystemMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_filesystem_test::DirectoryPath() );
		ret->AddItem( '2', std_filesystem_test::DirectoryIterator() );
		ret->AddItem( '3', std_filesystem_test::RecursiveDirectoryIterator() );
		ret->AddItem( '4', std_filesystem_test::PathOperation_1() );
		ret->AddItem( '5', std_filesystem_test::PathOperation_2() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}