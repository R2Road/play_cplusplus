#include "TemplatePracticeMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/template_practice_part_01_test.h"

#include "TemplateMenu.h"

r2tm::TitleFunctionT TemplatePracticeMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Template Practice";
	};
}
r2tm::DescriptionFunctionT TemplatePracticeMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT TemplatePracticeMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', template_practice_part_01_test::BufferWithTemplate() );
		ret->AddItem( '2', template_practice_part_01_test::VaridicMax() );


		ret->AddSplit();


		ret->AddMenu( 27, TemplateMenu() );
	};
}