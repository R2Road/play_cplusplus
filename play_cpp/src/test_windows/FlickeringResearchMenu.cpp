#include "FlickeringResearchMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/windows_terminal_flickering_research.h"

#include "test_windows/WindowsMenu.h"

r2cm::MenuUp FlickeringResearchMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', windows_terminal_flickering_research::OneByOne() );
		ret->AddItem( '2', windows_terminal_flickering_research::OneByOne_WithOut_CLS() );
		ret->AddItem( '3', windows_terminal_flickering_research::LineByLine() );
		ret->AddItem( '4', windows_terminal_flickering_research::PageByPage() );
		ret->AddItem( '5', windows_terminal_flickering_research::PageByPage_WithOut_CLS_1() );
		ret->AddItem( '6', windows_terminal_flickering_research::PageByPage_WithOut_CLS_2() );


		ret->AddSplit();


		ret->AddMenu<WindowsMenu>( 27 );
	}

	return ret;
}