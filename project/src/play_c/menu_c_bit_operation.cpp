#include "menu_c_bit_operation.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c_bit_operation.hpp"

#include "menu_c.hpp"

r2tm::TitleFunctionT Menu_C_BitOperation::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Bit Operation";
	};
}
r2tm::DescriptionFunctionT Menu_C_BitOperation::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_C_BitOperation::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_c_bit_operation::Operator() );
		mp->AddItem( '2', play_c_bit_operation::Operator_2() );
		mp->AddItem( '3', play_c_bit_operation::Complement() );
		mp->AddItem( '4', play_c_bit_operation::Add_Remove_Toggle() );
		mp->AddItem( '5', play_c_bit_operation::Mask() );



		mp->AddLineFeed();



		mp->AddItem( '6', play_c_bit_operation::Operator_XOR() );
		mp->AddItem( '7', play_c_bit_operation::XOR_Swap() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_c_bit_operation::Plus_1() );
		mp->AddItem( 'w', play_c_bit_operation::Plus_2() );
		mp->AddItem( 'e', play_c_bit_operation::Minus_1() );
		mp->AddItem( 'r', play_c_bit_operation::Minus_2() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_c_bit_operation::ETC_1() );
		mp->AddItem( 's', play_c_bit_operation::ETC_2() );



		mp->AddSplit();


		mp->AddMenu( 27, Menu_C() );
	};
}