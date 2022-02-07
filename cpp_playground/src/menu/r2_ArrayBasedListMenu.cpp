#include "pch.h"
#include "r2_ArrayBasedListMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_HobbyMenu.h"

#include "test_hobby/array_based_list_test.h"

namespace r2
{
	MenuUp ArrayBasedListMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', array_based_list_test::Basic::GetInstance() );
			ret->AddChild( '2', array_based_list_test::SizeAndClear::GetInstance() );
			ret->AddChild( '3', array_based_list_test::PushBack::GetInstance() );
			ret->AddChild( '4', array_based_list_test::Erase::GetInstance() );
			ret->AddChild( '5', array_based_list_test::Erase_2::GetInstance() );
			ret->AddChild( '6', array_based_list_test::IteratorOperator_Indirection_StructureDereference::GetInstance() );
			ret->AddChild( '7', array_based_list_test::RBegin_REnd::GetInstance() );
			ret->AddChild( '8', array_based_list_test::ImprovedEndIterator::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::HobbyMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}