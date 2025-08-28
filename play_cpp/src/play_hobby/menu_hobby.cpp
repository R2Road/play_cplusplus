#include "menu_hobby.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_spin_lock.hpp"

#include "menu_infinite_number.hpp"
#include "menu_list_based_on_array.hpp"
#include "menu_memory_pool.hpp"
#include "menu_property.hpp"
#include "menu_serialize.hpp"
#include "menu_tree.hpp"

#include "menu_root.hpp"

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
		mp->AddMessage( "작업중", r2tm::eColor::FG_LightYellow );
		mp->AddMenu( '1', Menu_InfiniteNumber() );



		mp->AddLineFeed();



		mp->AddMessage( "대기", r2tm::eColor::FG_LightGreen );
		mp->AddItem( 'q', play_spin_lock::Basic() );
		mp->AddMenu( 'w', Menu_Tree() );
		mp->AddMenu( 'e', Menu_Property() );
		mp->AddMenu( 'r', Menu_MemoryPool() );
		mp->AddMenu( 't', Menu_Serialize() );



		mp->AddLineFeed();



		mp->AddMessage( "완료", r2tm::eColor::FG_LightGreen );
		mp->AddMenu( 'z', Menu_ListBasedOnArray() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}