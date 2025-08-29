#include "menu_new.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_new.hpp"

#include "menu_cpp.hpp"

r2tm::TitleFunctionT Menu_New::GetTitleFunction() const
{
	return []()->const char*
	{
		return "New";
	};
}
r2tm::DescriptionFunctionT Menu_New::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_New::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_cpp_new::Basic() );
		mp->AddItem( '2', play_cpp_new::Array() );
		mp->AddItem( '3', play_cpp_new::PlacementNew() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_CPP() );
	};
}