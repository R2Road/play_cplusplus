#include "STDFileSystemMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test_cpp/item/filesystem_test.h"

#include "STDMenu.h"

r2cm::MenuUp FileSystemMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', filesystem_test::DirectoryPath::GetInstance() );
		ret->AddItem( '2', filesystem_test::DirectoryIterator::GetInstance() );
		ret->AddItem( '3', filesystem_test::RecursiveDirectoryIterator::GetInstance() );
		ret->AddItem( '4', filesystem_test::PathOperation_1::GetInstance() );
		ret->AddItem( '5', filesystem_test::PathOperation_2::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}