#include "menu_infinite_number.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_infinite_number.hpp"

#include "menu_hobby.hpp"

r2tm::TitleFunctionT Menu_InfiniteNumber::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Infinite Number";
	};
}
r2tm::DescriptionFunctionT Menu_InfiniteNumber::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_InfiniteNumber::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_infinite_number::Declaration() );
		mp->AddItem( '2', play_infinite_number::Operator_Plus() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Hobby() );
	};
}