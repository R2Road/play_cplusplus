#include "ListBasedOnArrayMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_list_based_on_array::Basic() );
		mp->AddItem( '2', play_list_based_on_array::PushFront() );
		mp->AddItem( '3', play_list_based_on_array::IteratorOperator_Indirection_StructureDereference() );
		mp->AddItem( '4', play_list_based_on_array::EndIterator() );
		mp->AddItem( '5', play_list_based_on_array::BeginIterator() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_list_based_on_array::Clear() );
		mp->AddItem( 'w', play_list_based_on_array::PushBack() );
		mp->AddItem( 'e', play_list_based_on_array::Erase() );
		mp->AddItem( 'r', play_list_based_on_array::RBegin_REnd() );


		mp->AddSplit();


		mp->AddMenu( 27, HobbyMenu() );
	};
}