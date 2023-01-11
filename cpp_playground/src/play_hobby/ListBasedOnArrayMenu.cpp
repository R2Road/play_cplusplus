#include "ListBasedOnArrayMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/list_based_on_array_play.h"

#include "HobbyMenu.h"

r2cm::MenuUp ListBasedOnArrayMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', list_based_on_array_play::Basic() );
		ret->AddItem( '2', list_based_on_array_play::PushFront() );
		ret->AddItem( '3', list_based_on_array_play::IteratorOperator_Indirection_StructureDereference() );
		ret->AddItem( '4', list_based_on_array_play::EndIterator() );
		ret->AddItem( '5', list_based_on_array_play::BeginIterator() );



		ret->AddLineFeed();



		ret->AddItem( 'q', list_based_on_array_play::Clear() );
		ret->AddItem( 'w', list_based_on_array_play::PushBack() );
		ret->AddItem( 'e', list_based_on_array_play::Erase() );
		ret->AddItem( 'r', list_based_on_array_play::RBegin_REnd() );


		ret->AddSplit();


		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}