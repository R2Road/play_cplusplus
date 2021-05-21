#include "pch.h"
#include "r2_TemplateMenu.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
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
			ret->AddChild(
				'1'
				, []()->const char* { return r2::VariadicTemplateMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::VariadicTemplateMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'2'
				, []()->const char* { return r2::TemplateMetaProgrammingMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplateMetaProgrammingMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);

			ret->AddChild(
				'3'
				, []()->const char* { return r2::TemplatePracticeMenu::GetTitle(); }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplatePracticeMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();
		}

		return ret;
	}
}