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
			ret->AddChild( '2', array_based_list_test::PushFront::GetInstance() );
			ret->AddChild( '3', array_based_list_test::EndIterator::GetInstance() );
			ret->AddChild( '4', array_based_list_test::BeginIterator::GetInstance() );
			ret->AddChild( '5', array_based_list_test::Clear::GetInstance() );

			ret->AddLineFeed();
			ret->AddLineFeed();

			ret->AddChild( 'w', array_based_list_test::PushBack::GetInstance() );
			ret->AddChild( 'e', array_based_list_test::Erase_1::GetInstance() );
			ret->AddChild( 'r', array_based_list_test::Erase_2::GetInstance() );
			ret->AddChild( 't', array_based_list_test::Erase_3::GetInstance() );
			ret->AddChild( 'y', array_based_list_test::IteratorOperator_Indirection_StructureDereference::GetInstance() );
			ret->AddChild( 'u', array_based_list_test::RBegin_REnd::GetInstance() );
			ret->AddChild( 'i', array_based_list_test::ImprovedEndIterator::GetInstance() );


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