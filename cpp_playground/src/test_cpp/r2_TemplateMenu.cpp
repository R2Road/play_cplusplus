#include "pch.h"
#include "r2_TemplateMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_eTestEndAction.h"

#include "r2_VariadicTemplateMenu.h"
#include "r2_TemplateMetaProgrammingMenu.h"
#include "r2_TemplatePracticeMenu.h"

#include "C_CPP_Menu.h"

namespace r2
{
	r2cm::MenuUp TemplateMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem(
				'1'
				, []()->const char* { return r2::VariadicTemplateMenu::GetTitle(); }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::VariadicTemplateMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);

			ret->AddItem(
				'2'
				, []()->const char* { return r2::TemplateMetaProgrammingMenu::GetTitle(); }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::TemplateMetaProgrammingMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);

			ret->AddItem(
				'3'
				, []()->const char* { return r2::TemplatePracticeMenu::GetTitle(); }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::TemplatePracticeMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( C_CPP_Menu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}