#include "TemplateMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/template_basic_test.h"
#include "item/template_practice_test_02.h"
#include "item/template_specialization_test.h"

#include "TemplateMetaProgrammingMenu.h"
#include "TemplatePracticeMenu.h"
#include "VariadicTemplateMenu.h"

#include "RootMenu.h"

r2cm::MenuUp TemplateMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', template_basic_test::MemberVariable() );
		ret->AddItem( '2', template_basic_test::Function_ReturnValue() );
		ret->AddItem( '3', template_basic_test::Function_Object() );



		ret->AddLineFeed();



		ret->AddItem( '6', template_practice_test_02::Basic() );



		ret->AddLineFeed();



		ret->AddItem( 'q', template_specialization_test::Basic() );



		ret->AddLineFeed();



		ret->AddMenu<VariadicTemplateMenu>( 'a' );
		ret->AddMenu<TemplateMetaProgrammingMenu>( 's' );
		ret->AddMenu<TemplatePracticeMenu>( 'd' );



		ret->AddSplit();



		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}