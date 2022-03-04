#include "pch.h"
#include "r2_TemplateMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "r2_VariadicTemplateMenu.h"
#include "r2_TemplateMetaProgrammingMenu.h"
#include "r2_TemplatePracticeMenu.h"

namespace r2
{
	MenuUp TemplateMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddItem(
				'1'
				, []()->const char* { return r2::VariadicTemplateMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::VariadicTemplateMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);

			ret->AddItem(
				'2'
				, []()->const char* { return r2::TemplateMetaProgrammingMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::TemplateMetaProgrammingMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);

			ret->AddItem(
				'3'
				, []()->const char* { return r2::TemplatePracticeMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::TemplatePracticeMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}