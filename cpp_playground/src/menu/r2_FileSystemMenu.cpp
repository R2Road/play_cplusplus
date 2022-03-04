#include "pch.h"
#include "r2_FileSystemMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/filesystem_test.h"

namespace r2
{
	MenuUp FileSystemMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

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
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}