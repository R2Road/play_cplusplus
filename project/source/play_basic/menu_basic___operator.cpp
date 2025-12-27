#include "menu_basic___operator.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_basic___operator_priority.hpp"
#include "play_basic___operator_ternary.hpp"

#include "menu_basic.hpp"

r2tm::TitleFunctionT Menu_Basic___Operator::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Operator";
	};
}
r2tm::DescriptionFunctionT Menu_Basic___Operator::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Basic___Operator::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_basic___operator_priority::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_basic___operator_ternary::Basic() );
		mp->AddItem( 'w', play_basic___operator_ternary::Comma() );
		mp->AddItem( 'e', play_basic___operator_ternary::Void() );



		mp->AddSplit();


		mp->AddMenu( 27, Menu_Basic() );
	};
}