#include "menu_align.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_alignas.hpp"
#include "play_cpp_alignof.hpp"

#include "menu_cpp.hpp"

r2tm::TitleFunctionT Menu_Align::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Align";
	};
}
r2tm::DescriptionFunctionT Menu_Align::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Align::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_cpp_alignof::PrimitiveType() );
		mp->AddItem( '2', play_cpp_alignof::STDContainer() );
		mp->AddItem( '3', play_cpp_alignof::Struct() );
		mp->AddItem( '4', play_cpp_alignof::MixedStruct() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_cpp_alignas::AlignAs() );
		mp->AddItem( 'w', play_cpp_alignas::Odd_Byte() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_CPP() );
	};
}