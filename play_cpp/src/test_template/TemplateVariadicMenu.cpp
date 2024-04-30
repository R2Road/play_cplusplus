#include "TemplateVariadicMenu.h"

#include "r2tm/r2tm_Director.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', template_variadic_test::SizeOfArgs() );
		ret->AddItem( '2', template_variadic_test::PrintValues() );
		ret->AddItem( '3', template_variadic_test::SumValues() );
		ret->AddItem( '4', template_variadic_test::SubtractValues() );


		ret->AddSplit();


		ret->AddMenu( 27, TemplateMenu() );
	};
}