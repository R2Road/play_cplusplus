#include "pch.h"
#include "r2_FileSystemMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/filesystem_test.h"

namespace r2
{
	MenuUp FileSystemMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', filesystem_test::DirectoryPath::GetInstance() );
			ret->AddChild( '2', filesystem_test::DirectoryIterator::GetInstance() );
			ret->AddChild( '3', filesystem_test::RecursiveDirectoryIterator::GetInstance() );
			ret->AddChild( '4', filesystem_test::PathOperation::GetInstance() );
			ret->AddChild( '5', filesystem_test::PathOperation_2::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}