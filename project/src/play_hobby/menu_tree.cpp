#include "menu_tree.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_tree.hpp"

#include "menu_hobby.hpp"

r2tm::TitleFunctionT Menu_Tree::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Tree";
	};
}
r2tm::DescriptionFunctionT Menu_Tree::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Tree::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp ) {
		mp->AddItem( '1', play_tree::Basic() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Hobby() );
	};
}