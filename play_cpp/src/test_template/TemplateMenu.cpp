#include "TemplateMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/template_basic_test.h"
#include "item/template_practice_test_02.h"
#include "item/template_specialization_test.h"

#include "TemplateMetaProgrammingMenu.h"
#include "TemplatePracticeMenu.h"
#include "VariadicTemplateMenu.h"

#include "RootMenu.h"

r2tm::TitleFunctionT TemplateMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Template";
	};
}
r2tm::DescriptionFunctionT TemplateMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT TemplateMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', template_basic_test::MemberVariable() );
		ret->AddItem( '2', template_basic_test::Function_ReturnValue() );
		ret->AddItem( '3', template_basic_test::Function_Object() );
		ret->AddItem( '4', template_basic_test::RemovePointer() );



		ret->AddLineFeed();



		ret->AddItem( '6', template_practice_test_02::Basic() );



		ret->AddLineFeed();



		ret->AddItem( 'q', template_specialization_test::Basic() );



		ret->AddLineFeed();



		ret->AddMenu( 'a', TemplateVariadicMenu() );
		ret->AddMenu( 's', TemplateMetaProgrammingMenu() );
		ret->AddMenu( 'd', TemplatePracticeMenu() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}