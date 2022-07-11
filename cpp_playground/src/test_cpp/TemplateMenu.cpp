#include "TemplateMenu.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Director.h"

#include "VariadicTemplateMenu.h"
#include "TemplateMetaProgrammingMenu.h"
#include "TemplatePracticeMenu.h"

#include "C_CPP_Menu.h"

r2cm::MenuUp TemplateMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem(
			'1'
			, []()->const char* { return VariadicTemplateMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( VariadicTemplateMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);

		ret->AddItem(
			'2'
			, []()->const char* { return TemplateMetaProgrammingMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TemplateMetaProgrammingMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);

		ret->AddItem(
			'3'
			, []()->const char* { return TemplatePracticeMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TemplatePracticeMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( C_CPP_Menu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}