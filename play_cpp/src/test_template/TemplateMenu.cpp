#include "TemplateMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "item/template_basic_test.h"
#include "item/template_practice_test_02.h"
#include "item/template_specialization_test.h"

#include "TemplateMetaProgrammingMenu.h"
#include "TemplatePracticeMenu.h"
#include "TemplateVariadicMenu.h"

#include "menu_root.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', template_basic_test::MemberVariable() );
		mp->AddItem( '2', template_basic_test::Function_ReturnValue() );
		mp->AddItem( '3', template_basic_test::Function_Object() );
		mp->AddItem( '4', template_basic_test::RemovePointer() );
		mp->AddItem( '5', template_basic_test::Constant() );
		mp->AddItem( '6', template_basic_test::Parentheses() );



		mp->AddLineFeed();



		mp->AddItem( '7', template_practice_test_02::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'q', template_specialization_test::Basic() );



		mp->AddLineFeed();



		mp->AddMenu( 'a', TemplateVariadicMenu() );
		mp->AddMenu( 's', TemplateMetaProgrammingMenu() );
		mp->AddMenu( 'd', TemplatePracticeMenu() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}