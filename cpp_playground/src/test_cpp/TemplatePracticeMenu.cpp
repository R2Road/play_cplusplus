#include "TemplatePracticeMenu.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Director.h"

#include "test_cpp/item/template_practice_part_01_test.h"

#include "TemplateMenu.h"

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
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TemplateMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}