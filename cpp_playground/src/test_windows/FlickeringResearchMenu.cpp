#include "FlickeringResearchMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "item/flickering_research.h"

#include "test_windows/TestWindowsMenu.h"

r2cm::MenuUp FlickeringResearchMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', flickering_research::OneByOne::GetInstance() );
		ret->AddItem( '2', flickering_research::OneByOne_WithOut_CLS::GetInstance() );
		ret->AddItem( '3', flickering_research::LineByLine::GetInstance() );
		ret->AddItem( '4', flickering_research::PageByPage::GetInstance() );
		ret->AddItem( '5', flickering_research::PageByPage_WithOut_CLS_1::GetInstance() );
		ret->AddItem( '6', flickering_research::PageByPage_WithOut_CLS_2::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TestWindowsMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}