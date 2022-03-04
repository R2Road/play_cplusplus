#include "pch.h"
#include "r2_TemplatePracticeMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_TemplateMenu.h"

#include "test_cpp/template_practice_part_01_test.h"

namespace r2
{
	r2cm::MenuUp TemplatePracticeMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', template_practice_part_01_test::BufferWithTemplate::GetInstance() );
			ret->AddItem( '2', template_practice_part_01_test::VaridicMax::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}