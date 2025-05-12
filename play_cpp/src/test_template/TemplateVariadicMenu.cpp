#include "TemplateVariadicMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_template/item/template_variadic_test.h"

#include "TemplateMenu.h"

r2tm::TitleFunctionT TemplateVariadicMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Variadic";
	};
}
r2tm::DescriptionFunctionT TemplateVariadicMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT TemplateVariadicMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', template_variadic_test::SizeOfArgs() );
		mp->AddItem( '2', template_variadic_test::PrintValues() );
		mp->AddItem( '3', template_variadic_test::SumValues() );
		mp->AddItem( '4', template_variadic_test::SubtractValues() );


		mp->AddLineFeed();
		mp->AddLineFeed();


		mp->AddItem( 'a', template_variadic_test::Test() );


		mp->AddSplit();


		mp->AddMenu( 27, TemplateMenu() );
	};
}