#include "pch.h"
#include "r2_HobbyMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_hobby/array_based_list_test.h"
#include "test_hobby/infinite_number_test.h"
#include "test_hobby/memory_pool_test.h"

namespace r2
{
	MenuUp HobbyMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', infinite_number_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( '2', array_based_list_test::Basic_1::GetInstance() );
			ret->AddChild( '3', array_based_list_test::PushBack::GetInstance() );
			ret->AddChild( '4', array_based_list_test::Erase::GetInstance() );
			ret->AddChild( '5', array_based_list_test::IteratorOperator_Indirection_StructureDereference::GetInstance() );
			ret->AddChild( '6', array_based_list_test::RBegin_REnd::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'q', memory_pool_test::Step01::GetInstance() );


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