#include "FlickeringResearchMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "item/windows_terminal_flickering_research.h"

#include "test_windows/WindowsMenu.h"

r2tm::TitleFunctionT FlickeringResearchMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Flickering Research";
	};
}
r2tm::DescriptionFunctionT FlickeringResearchMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT FlickeringResearchMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', windows_terminal_flickering_research::OneByOne() );
		mp->AddItem( '2', windows_terminal_flickering_research::OneByOne_WithOut_CLS() );
		mp->AddItem( '3', windows_terminal_flickering_research::LineByLine() );
		mp->AddItem( '4', windows_terminal_flickering_research::PageByPage() );
		mp->AddItem( '5', windows_terminal_flickering_research::PageByPage_WithOut_CLS_1() );
		mp->AddItem( '6', windows_terminal_flickering_research::PageByPage_WithOut_CLS_2() );


		mp->AddSplit();


		mp->AddMenu( 27, WindowsMenu() );
	};
}