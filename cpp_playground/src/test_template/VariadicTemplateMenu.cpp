#include "VariadicTemplateMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_template/item/variadic_template_test.h"

#include "TemplateMenu.h"

r2cm::MenuUp VariadicTemplateMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', variadic_template_test::SizeOfArgs::GetInstance() );
		ret->AddItem( '2', variadic_template_test::PrintValues::GetInstance() );
		ret->AddItem( '3', variadic_template_test::SumValues::GetInstance() );
		ret->AddItem( '4', variadic_template_test::SubtractValues::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<TemplateMenu>( 27 );
	}

	return ret;
}