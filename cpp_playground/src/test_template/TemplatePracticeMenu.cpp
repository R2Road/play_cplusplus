#include "TemplatePracticeMenu.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Director.h"

#include "item/template_practice_part_01_test.h"

#include "TemplateMenu.h"

r2cm::MenuUp TemplatePracticeMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', template_practice_part_01_test::BufferWithTemplate() );
		ret->AddItem( '2', template_practice_part_01_test::VaridicMax() );


		ret->AddSplit();


		ret->AddMenu<TemplateMenu>( 27 );
	}

	return ret;
}