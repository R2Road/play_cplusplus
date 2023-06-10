#include "TemplateMetaProgrammingMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/template_meta_programming_01_test.h"
#include "item/template_meta_programming_02_test.h"
#include "item/template_meta_programming_03_test.h"

#include "TemplateMenu.h"

r2tm::TitleFunctionT TemplateMetaProgrammingMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Template Meta Programming";
	};
}
r2tm::DescriptionFunctionT TemplateMetaProgrammingMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT TemplateMetaProgrammingMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', template_meta_programming_test::CalculateFactorial() );
		ret->AddItem( '2', template_meta_programming_test::GreatestCommonDivisor() );
		ret->AddItem( '3', template_meta_programming_test::BasicRatio() );
		ret->AddItem( '4', template_meta_programming_test::SumBasicRatio() );
		ret->AddItem( '5', template_meta_programming_test::RatioWithGCD() );
		ret->AddItem( '6', template_meta_programming_test::SumRatioWithGCD() );
		ret->AddItem( '7', template_meta_programming_test::SumRatioAndOperator1() );
		ret->AddItem( '8', template_meta_programming_test::SumRatioAndOperator2() );


		ret->AddLineFeed();


		ret->AddItem( 'q', template_meta_programming_test::Character2String() );
		ret->AddItem( 'w', template_meta_programming_test::Integer2String() );
		ret->AddItem( 'e', template_meta_programming_test::CalculatePlaceValue() );
		ret->AddItem( 'r', template_meta_programming_test::Integer2String_II() );


		ret->AddLineFeed();


		ret->AddItem( 'a', template_meta_programming_test::MultiTypePackage() );


		ret->AddSplit();


		ret->AddMenu( 27, TemplateMenu() );
	};
}