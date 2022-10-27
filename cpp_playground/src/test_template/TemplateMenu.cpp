#include "TemplateMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/template_specialization_test.h"

#include "TemplateMetaProgrammingMenu.h"
#include "TemplatePracticeMenu.h"
#include "VariadicTemplateMenu.h"

#include "RootMenu.h"

r2cm::MenuUp TemplateMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', template_specialization_test::Basic::GetInstance() );



		ret->AddLineFeed();



		ret->AddMenu<VariadicTemplateMenu>( 'q' );
		ret->AddMenu<TemplateMetaProgrammingMenu>( 'w' );
		ret->AddMenu<TemplatePracticeMenu>( 'e' );



		ret->AddSplit();



		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}