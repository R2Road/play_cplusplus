#include "pch.h"
#include "r2_ArrayBasedListMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_HobbyMenu.h"

#include "test_hobby/array_based_list_test.h"

namespace r2
{
	MenuUp ArrayBasedListMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', array_based_list_test::Basic::GetInstance() );
			ret->AddItem( '2', array_based_list_test::PushFront::GetInstance() );
			ret->AddItem( '3', array_based_list_test::IteratorOperator_Indirection_StructureDereference::GetInstance() );
			ret->AddItem( '4', array_based_list_test::EndIterator::GetInstance() );
			ret->AddItem( '5', array_based_list_test::BeginIterator::GetInstance() );

			ret->AddLineFeed();
			ret->AddLineFeed();

			ret->AddItem( 'q', array_based_list_test::Clear::GetInstance() );
			ret->AddItem( 'w', array_based_list_test::PushBack::GetInstance() );
			ret->AddItem( 'e', array_based_list_test::Erase::GetInstance() );
			ret->AddItem( 'r', array_based_list_test::RBegin_REnd::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::HobbyMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}