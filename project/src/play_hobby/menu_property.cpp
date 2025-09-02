#include "menu_property.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_property.hpp"

#include "menu_hobby.hpp"

r2tm::TitleFunctionT Menu_Property::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Property";
	};
}
r2tm::DescriptionFunctionT Menu_Property::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Property::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_property::Functor() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Hobby() );
	};
}