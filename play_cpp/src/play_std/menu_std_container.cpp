#include "menu_std_container.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_array.hpp"
#include "play_std_bitset.hpp"
#include "play_std_list.hpp"
#include "play_std_queue.hpp"
#include "play_std_unordered_map.hpp"
#include "play_std_vector.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT STDContainerMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Container";
	};
}
r2tm::DescriptionFunctionT STDContainerMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDContainerMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_array::Declaration() );
		mp->AddItem( '2', play_std_array::Fill() );
		mp->AddItem( '3', play_std_array::Copy() );


		mp->AddLineFeed();


		mp->AddItem( '6', play_std_bitset::All_Any_None() );
		mp->AddItem( '7', play_std_bitset::Set_And_Test() );
		mp->AddItem( '8', play_std_bitset::Size() );
		mp->AddItem( '9', play_std_bitset::Operator() );


		mp->AddLineFeed();


		mp->AddItem( 'q', play_std_list::Insert() );
		mp->AddItem( 'w', play_std_list::Splice_Single() );
		mp->AddItem( 'e', play_std_list::Splice_Range() );
		mp->AddItem( 'r', play_std_list::Erase() );
		mp->AddItem( 't', play_std_list::Erase_OthersIterator() );
		mp->AddItem( 'y', play_std_list::EndIterator() );


		mp->AddLineFeed();


		mp->AddItem( 'a', play_std_vector::Resize() );
		mp->AddItem( 's', play_std_vector::Resize_And_Memory() );
		mp->AddItem( 'd', play_std_vector::Clear() );
		mp->AddItem( 'f', play_std_vector::Reserve() );
		mp->AddItem( 'g', play_std_vector::NoneDefaultConstructor() );
		mp->AddItem( 'h', play_std_vector::BoolVector() );
		mp->AddItem( 'j', play_std_vector::OthersIterator() );
		mp->AddItem( 'k', play_std_vector::EndIterator() );
		mp->AddItem( 'l', play_std_vector::Move() );


		mp->AddLineFeed();


		mp->AddItem( 'z', play_std_queue::Declaration() );
		mp->AddItem( 'x', play_std_queue::Front_Back() );
		mp->AddItem( 'c', play_std_queue::Push_Pop() );
		mp->AddItem( 'v', play_std_queue::Iteration() );


		mp->AddLineFeed();


		mp->AddItem( 'n', play_std_unordered_map::CString() );


		mp->AddSplit();


		mp->AddMenu( 27, STDMenu() );
	};
}