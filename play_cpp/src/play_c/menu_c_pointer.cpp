#include "menu_c_pointer.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_c_pointer.hpp"

#include "menu_c.hpp"

r2tm::TitleFunctionT Menu_C_Pointer::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Pointer";
	};
}
r2tm::DescriptionFunctionT Menu_C_Pointer::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_C_Pointer::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_c_pointer::Basic() );
		mp->AddItem( '2', play_c_pointer::Offset() );
		mp->AddItem( '3', play_c_pointer::Pointer2Index() );
		mp->AddItem( '4', play_c_pointer::ConstPointer() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_c_pointer::CharacterPointer_Length_0() );
		mp->AddItem( 'w', play_c_pointer::MemberAddress() );
		mp->AddItem( 'e', play_c_pointer::StackAddress() );



		mp->AddSplit();


		mp->AddMenu( 27, Menu_C() );
	};
}