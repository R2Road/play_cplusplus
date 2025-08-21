#include "TemplateMetaProgrammingMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', template_meta_programming_test::CalculateFactorial() );
		mp->AddItem( '2', template_meta_programming_test::GreatestCommonDivisor() );
		mp->AddItem( '3', template_meta_programming_test::BasicRatio() );
		mp->AddItem( '4', template_meta_programming_test::SumBasicRatio() );
		mp->AddItem( '5', template_meta_programming_test::RatioWithGCD() );
		mp->AddItem( '6', template_meta_programming_test::SumRatioWithGCD() );
		mp->AddItem( '7', template_meta_programming_test::SumRatioAndOperator1() );
		mp->AddItem( '8', template_meta_programming_test::SumRatioAndOperator2() );


		mp->AddLineFeed();


		mp->AddItem( 'q', template_meta_programming_test::Character2String() );
		mp->AddItem( 'w', template_meta_programming_test::Integer2String() );
		mp->AddItem( 'e', template_meta_programming_test::CalculatePlaceValue() );
		mp->AddItem( 'r', template_meta_programming_test::Integer2String_II() );


		mp->AddLineFeed();


		mp->AddItem( 'a', template_meta_programming_test::MultiTypePackage() );


		mp->AddSplit();


		mp->AddMenu( 27, TemplateMenu() );
	};
}