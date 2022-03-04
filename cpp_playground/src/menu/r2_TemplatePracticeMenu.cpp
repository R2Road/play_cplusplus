#include "pch.h"
#include "r2_TemplatePracticeMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_TemplateMenu.h"

#include "test_cpp/template_practice_part_01_test.h"

namespace r2
{
	MenuUp TemplatePracticeMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', template_practice_part_01_test::BufferWithTemplate::GetInstance() );
			ret->AddItem( '2', template_practice_part_01_test::VaridicMax::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}