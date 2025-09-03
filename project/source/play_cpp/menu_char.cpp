#include "menu_char.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_char.hpp"
#include "play_cpp_korean.hpp"
#include "play_cpp_locale.hpp"

#include "menu_cpp.hpp"

r2tm::TitleFunctionT Menu_Char::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Char";
	};
}
r2tm::DescriptionFunctionT Menu_Char::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Char::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_cpp_char::Basic() );
		mp->AddItem( '2', play_cpp_char::Encoding() );
		mp->AddItem( '3', play_cpp_locale::Basic() );
		mp->AddItem( '4', play_cpp_char::RawStringLiteral() );


		mp->AddLineFeed();


		mp->AddItem( 'z', play_cpp_korean::Basic() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_CPP() );
	};
}