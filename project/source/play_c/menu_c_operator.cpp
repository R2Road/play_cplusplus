#include "menu_c_operator.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c_operator_priority.hpp"
#include "play_c_operator_ternary.hpp"

#include "menu_c.hpp"

r2tm::TitleFunctionT Menu_C_Operator::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Operator";
	};
}
r2tm::DescriptionFunctionT Menu_C_Operator::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_C_Operator::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_c_operator_priority::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_c_operator_ternary::Basic() );
		mp->AddItem( 'w', play_c_operator_ternary::Comma() );
		mp->AddItem( 'e', play_c_operator_ternary::Void() );



		mp->AddSplit();


		mp->AddMenu( 27, Menu_C() );
	};
}