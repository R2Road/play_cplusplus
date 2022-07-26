#include "TemplateMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "VariadicTemplateMenu.h"
#include "TemplateMetaProgrammingMenu.h"
#include "TemplatePracticeMenu.h"

#include "CPP_Menu.h"

r2cm::MenuUp TemplateMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddMenu<VariadicTemplateMenu>( '1' );
		ret->AddMenu<TemplateMetaProgrammingMenu>( '2' );
		ret->AddMenu<TemplatePracticeMenu>( '3' );


		ret->AddSplit();


		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}