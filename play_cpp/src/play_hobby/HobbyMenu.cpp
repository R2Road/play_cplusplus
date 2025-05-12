#include "HobbyMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_infinite_number::Declaration() );
		mp->AddItem( '2', play_infinite_number::Operator_Plus() );



		mp->AddLineFeed();



		mp->AddItem( '9', play_spin_lock::Basic() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', TreeMenu() );
		mp->AddMenu( 'w', PropertyMenu() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_serialize::Basic() );
		mp->AddItem( 's', play_serialize::Copy() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', ListBasedOnArrayMenu() );
		mp->AddMenu( 'x', Vector3Menu() );
		mp->AddMenu( 'c', MemoryPoolMenu() );


		mp->AddSplit();


		mp->AddMenu( 27, RootMenu() );
	};
}