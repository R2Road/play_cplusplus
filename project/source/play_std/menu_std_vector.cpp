#include "menu_std_vector.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_vector.hpp"

#include "menu_std_container.hpp"

r2tm::TitleFunctionT Menu_STD_Vector::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<vector>";
	};
}
r2tm::DescriptionFunctionT Menu_STD_Vector::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_STD_Vector::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_vector::Resize() );
		mp->AddItem( '2', play_std_vector::Resize_And_Memory() );
		mp->AddItem( '3', play_std_vector::Clear() );
		mp->AddItem( '4', play_std_vector::Reserve() );
		mp->AddItem( '5', play_std_vector::NoneDefaultConstructor() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_std_vector::BoolVector() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_std_vector::OthersIterator() );
		mp->AddItem( 's', play_std_vector::EndIterator() );
		mp->AddItem( 'd', play_std_vector::Move() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_STDContainer() );
	};
}