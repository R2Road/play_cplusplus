#include "ListBasedOnArrayMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/play_list_based_on_array.h"

#include "HobbyMenu.h"

r2tm::TitleFunctionT ListBasedOnArrayMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "List Based On Array";
	};
}
r2tm::DescriptionFunctionT ListBasedOnArrayMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT ListBasedOnArrayMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
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


		ret->AddMenu( 27, HobbyMenu() );
	};
}