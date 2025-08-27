#include "menu_hobby.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_infinite_number.hpp"
#include "play_serialize.hpp"
#include "play_spin_lock.hpp"

#include "menu_list_based_on_array.hpp"
#include "menu_memory_pool.hpp"
#include "menu_property.hpp"
#include "menu_tree.hpp"

#include "menu_root.h"

r2tm::TitleFunctionT Menu_Hobby::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Hobby";
	};
}
r2tm::DescriptionFunctionT Menu_Hobby::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Hobby::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_infinite_number::Declaration() );
		mp->AddItem( '2', play_infinite_number::Operator_Plus() );



		mp->AddLineFeed();



		mp->AddItem( '9', play_spin_lock::Basic() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', Menu_Tree() );
		mp->AddMenu( 'w', Menu_Property() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_serialize::Basic() );
		mp->AddItem( 's', play_serialize::Copy() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', Menu_ListBasedOnArray() );
		mp->AddMenu( 'x', Menu_MemoryPool() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}