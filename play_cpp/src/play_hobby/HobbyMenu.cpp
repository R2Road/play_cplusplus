#include "HobbyMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/play_infinite_number.h"
#include "item/play_serialize.h"
#include "item/play_spin_lock.h"

#include "ListBasedOnArrayMenu.h"
#include "MemoryPoolMenu.h"
#include "PropertyMenu.h"
#include "TreeMenu.h"
#include "Vector3Menu.h"

#include "RootMenu.h"

r2tm::TitleFunctionT HobbyMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Hobby";
	};
}
r2tm::DescriptionFunctionT HobbyMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT HobbyMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', play_infinite_number::Declaration() );
		ret->AddItem( '2', play_infinite_number::Operator_Plus() );



		ret->AddLineFeed();



		ret->AddItem( '9', play_spin_lock::Basic() );



		ret->AddLineFeed();



		ret->AddMenu( 'q', TreeMenu() );
		ret->AddMenu( 'w', PropertyMenu() );



		ret->AddLineFeed();



		ret->AddItem( 'a', play_serialize::Basic() );
		ret->AddItem( 's', play_serialize::Copy() );



		ret->AddLineFeed();



		ret->AddMenu( 'z', ListBasedOnArrayMenu() );
		ret->AddMenu( 'x', Vector3Menu() );
		ret->AddMenu( 'c', MemoryPoolMenu() );


		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}