#include "FlickeringResearchMenu.h"

#include "r2tm/r2tm_Director.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', windows_terminal_flickering_research::OneByOne() );
		ret->AddItem( '2', windows_terminal_flickering_research::OneByOne_WithOut_CLS() );
		ret->AddItem( '3', windows_terminal_flickering_research::LineByLine() );
		ret->AddItem( '4', windows_terminal_flickering_research::PageByPage() );
		ret->AddItem( '5', windows_terminal_flickering_research::PageByPage_WithOut_CLS_1() );
		ret->AddItem( '6', windows_terminal_flickering_research::PageByPage_WithOut_CLS_2() );


		ret->AddSplit();


		ret->AddMenu( 27, WindowsMenu() );
	};
}