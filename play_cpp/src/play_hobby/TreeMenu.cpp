#include "TreeMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

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
	return[]( r2tm::MenuProcessor* mp ) {
		mp->AddItem( '1', play_tree::Basic() );



		mp->AddSplit();



		mp->AddMenu( 27, HobbyMenu() );
	};
}