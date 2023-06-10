#include "PropertyMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/play_property.h"

#include "HobbyMenu.h"

r2tm::TitleFunctionT PropertyMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Property";
	};
}
r2tm::DescriptionFunctionT PropertyMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT PropertyMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', play_property::Functor() );



		ret->AddSplit();



		ret->AddMenu( 27, HobbyMenu() );
	};
}