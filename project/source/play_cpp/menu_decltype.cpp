#include "menu_decltype.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_decltype.hpp"

#include "menu_cpp.hpp"

r2tm::TitleFunctionT Menu_Decltype::GetTitleFunction() const
{
	return []()->const char*
	{
		return "decltype";
	};
}
r2tm::DescriptionFunctionT Menu_Decltype::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Decltype::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_cpp_decltype::Basic() );
		mp->AddItem( '2', play_cpp_decltype::Function() );
		mp->AddItem( '3', play_cpp_decltype::Lambda() );
		mp->AddItem( '4', play_cpp_decltype::Template() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_CPP() );
	};
}