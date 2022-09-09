#include "ArrayBasedListMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/array_based_list_test.h"

#include "HobbyMenu.h"

r2cm::MenuUp ListBasedOnArrayMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', array_based_list_test::Basic::GetInstance() );
		ret->AddItem( '2', array_based_list_test::PushFront::GetInstance() );
		ret->AddItem( '3', array_based_list_test::IteratorOperator_Indirection_StructureDereference::GetInstance() );
		ret->AddItem( '4', array_based_list_test::EndIterator::GetInstance() );
		ret->AddItem( '5', array_based_list_test::BeginIterator::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', array_based_list_test::Clear::GetInstance() );
		ret->AddItem( 'w', array_based_list_test::PushBack::GetInstance() );
		ret->AddItem( 'e', array_based_list_test::Erase::GetInstance() );
		ret->AddItem( 'r', array_based_list_test::RBegin_REnd::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}