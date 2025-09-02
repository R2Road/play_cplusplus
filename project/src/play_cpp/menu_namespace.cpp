#include "menu_namespace.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_namespace.hpp"

#include "menu_cpp.hpp"

r2tm::TitleFunctionT Menu_NameSpace::GetTitleFunction() const
{
	return []()->const char*
	{
		return "NameSpace";
	};
}
r2tm::DescriptionFunctionT Menu_NameSpace::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_NameSpace::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_cpp_namespace::Basic() );
		mp->AddItem( '2', play_cpp_namespace::Alias() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_CPP() );
	};
}