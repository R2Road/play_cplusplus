#include "menu_c_union.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c_union.hpp"

#include "menu_c.hpp"

r2tm::TitleFunctionT Menu_C_Union::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Union";
	};
}
r2tm::DescriptionFunctionT Menu_C_Union::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_C_Union::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_c_union::Basic() );
		mp->AddItem( '2', play_c_union::Memory() );
		mp->AddItem( '3', play_c_union::Assign() );
		mp->AddItem( '4', play_c_union::Complex() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_c_union::Unnamed_Union_With_Struct() );
		mp->AddItem( 'w', play_c_union::Unnamed_Union_With_Vector3() );
		mp->AddItem( 'e', play_c_union::Unnamed_Union_With_Vector3_2() );
		mp->AddItem( 'r', play_c_union::Unnamed_Union_With_Vector3_3() );
		mp->AddItem( 't', play_c_union::Unnamed_Union_With_Vector3_4() );
		mp->AddItem( 'y', play_c_union::Unnamed_Union_With_Vector3_5() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_C() );
	};
}