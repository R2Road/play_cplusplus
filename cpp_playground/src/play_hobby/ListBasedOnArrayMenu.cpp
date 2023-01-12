#include "ListBasedOnArrayMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/play_list_based_on_array.h"

#include "HobbyMenu.h"

r2cm::MenuUp ListBasedOnArrayMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', play_list_based_on_array::Basic() );
		ret->AddItem( '2', play_list_based_on_array::PushFront() );
		ret->AddItem( '3', play_list_based_on_array::IteratorOperator_Indirection_StructureDereference() );
		ret->AddItem( '4', play_list_based_on_array::EndIterator() );
		ret->AddItem( '5', play_list_based_on_array::BeginIterator() );



		ret->AddLineFeed();



		ret->AddItem( 'q', play_list_based_on_array::Clear() );
		ret->AddItem( 'w', play_list_based_on_array::PushBack() );
		ret->AddItem( 'e', play_list_based_on_array::Erase() );
		ret->AddItem( 'r', play_list_based_on_array::RBegin_REnd() );


		ret->AddSplit();


		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}