#include "ListBasedOnArrayMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/list_based_on_array_test.h"

#include "HobbyMenu.h"

r2cm::MenuUp ListBasedOnArrayMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', list_based_on_array_test::Basic::GetInstance() );
		ret->AddItem( '2', list_based_on_array_test::PushFront::GetInstance() );
		ret->AddItem( '3', list_based_on_array_test::IteratorOperator_Indirection_StructureDereference::GetInstance() );
		ret->AddItem( '4', list_based_on_array_test::EndIterator::GetInstance() );
		ret->AddItem( '5', list_based_on_array_test::BeginIterator::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', list_based_on_array_test::Clear::GetInstance() );
		ret->AddItem( 'w', list_based_on_array_test::PushBack::GetInstance() );
		ret->AddItem( 'e', list_based_on_array_test::Erase::GetInstance() );
		ret->AddItem( 'r', list_based_on_array_test::RBegin_REnd::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}