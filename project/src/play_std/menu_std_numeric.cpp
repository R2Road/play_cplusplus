#include "menu_std_numeric.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_std_numeric.hpp"

#include "menu_std.hpp"

r2tm::TitleFunctionT Menu_STDNumeric::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<numeric>";
	};
}
r2tm::DescriptionFunctionT Menu_STDNumeric::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_STDNumeric::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_std_numeric::Min() );
		mp->AddItem( '2', play_std_numeric::Max() );
		mp->AddItem( '3', play_std_numeric::Accumulate_Number() );
		mp->AddItem( '4', play_std_numeric::Accumulate_String() );
		mp->AddItem( '5', play_std_numeric::Partial_Sum() );
		mp->AddItem( '6', play_std_numeric::FillSequenceNumber() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_STD() );
	};
}