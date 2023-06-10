#include "TreeMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/play_tree.h"

#include "HobbyMenu.h"

r2tm::TitleFunctionT TreeMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Tree";
	};
}
r2tm::DescriptionFunctionT TreeMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT TreeMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret ) {
		ret->AddItem( '1', play_tree::Basic() );



		ret->AddSplit();



		ret->AddMenu( 27, HobbyMenu() );
	};
}