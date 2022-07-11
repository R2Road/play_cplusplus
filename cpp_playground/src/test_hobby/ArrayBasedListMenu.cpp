#include "ArrayBasedListMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"
#include "HobbyMenu.h"

#include "test_hobby/item/array_based_list_test.h"

r2cm::MenuUp ArrayBasedListMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

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
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( HobbyMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}