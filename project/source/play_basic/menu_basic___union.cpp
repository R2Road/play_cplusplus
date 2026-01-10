#include "menu_basic___union.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_basic_union.hpp"

#include "menu_basic.hpp"

r2tm::TitleFunctionT Menu_Basic___Union::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Union";
	};
}
r2tm::DescriptionFunctionT Menu_Basic___Union::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Basic___Union::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_basic_union::Basic() );
		mp->AddItem( '2', play_basic_union::Memory() );
		mp->AddItem( '3', play_basic_union::Assign() );
		mp->AddItem( '4', play_basic_union::Complex() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_basic_union::Unnamed_Union_With_Struct() );
		mp->AddItem( 'w', play_basic_union::Unnamed_Union_With_Vector3() );
		mp->AddItem( 'e', play_basic_union::Unnamed_Union_With_Vector3_2() );
		mp->AddItem( 'r', play_basic_union::Unnamed_Union_With_Vector3_3() );
		mp->AddItem( 't', play_basic_union::Unnamed_Union_With_Vector3_4() );
		mp->AddItem( 'y', play_basic_union::Unnamed_Union_With_Vector3_5() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Basic() );
	};
}