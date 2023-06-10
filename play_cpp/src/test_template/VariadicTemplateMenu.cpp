#include "VariadicTemplateMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_template/item/variadic_template_test.h"

#include "TemplateMenu.h"

r2tm::TitleFunctionT VariadicTemplateMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Variadic Template";
	};
}
r2tm::DescriptionFunctionT VariadicTemplateMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT VariadicTemplateMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', variadic_template_test::SizeOfArgs() );
		ret->AddItem( '2', variadic_template_test::PrintValues() );
		ret->AddItem( '3', variadic_template_test::SumValues() );
		ret->AddItem( '4', variadic_template_test::SubtractValues() );


		ret->AddSplit();


		ret->AddMenu( 27, TemplateMenu() );
	};
}