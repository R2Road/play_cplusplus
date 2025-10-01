#include "menu_various.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_various_0.hpp"

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_Various::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Various";
	};
}
r2tm::DescriptionFunctionT Menu_Various::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Various::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_various_0::ShowBinary() );
		mp->AddItem( '2', play_various_0::LifeTimeTest() );
		mp->AddItem( '3', play_various_0::STDFunctionImplement() );

		mp->AddItem( '5', play_various_0::CircularReference() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_various_0::E() );
		mp->AddItem( 'w', play_various_0::Init_Class_Array() );
		mp->AddItem( 'e', play_various_0::Float_Binary() );
		mp->AddItem( 'r', play_various_0::Forced_Call() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}