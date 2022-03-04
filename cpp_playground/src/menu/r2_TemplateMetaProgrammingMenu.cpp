#include "pch.h"
#include "r2_TemplateMetaProgrammingMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_TemplateMenu.h"

#include "test_cpp/template_meta_programming_01_test.h"
#include "test_cpp/template_meta_programming_02_test.h"
#include "test_cpp/template_meta_programming_03_test.h"

namespace r2
{
	r2cm::MenuUp TemplateMetaProgrammingMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, "Template Meta Programming" ) );

		{
			ret->AddItem( '1', template_meta_programming_test::CalculateFactorial::GetInstance() );
			ret->AddItem( '2', template_meta_programming_test::GreatestCommonDivisor::GetInstance() );
			ret->AddItem( '3', template_meta_programming_test::BasicRatio::GetInstance() );
			ret->AddItem( '4', template_meta_programming_test::SumBasicRatio::GetInstance() );
			ret->AddItem( '5', template_meta_programming_test::RatioWithGCD::GetInstance() );
			ret->AddItem( '6', template_meta_programming_test::SumRatioWithGCD::GetInstance() );
			ret->AddItem( '7', template_meta_programming_test::SumRatioAndOperator1::GetInstance() );
			ret->AddItem( '8', template_meta_programming_test::SumRatioAndOperator2::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'q', template_meta_programming_test::Character2String::GetInstance() );
			ret->AddItem( 'w', template_meta_programming_test::Integer2String::GetInstance() );
			ret->AddItem( 'e', template_meta_programming_test::CalculatePlaceValue::GetInstance() );
			ret->AddItem( 'r', template_meta_programming_test::Integer2String_II::GetInstance() );


			ret->AddLineFeed();


			ret->AddItem( 'a', template_meta_programming_test::MultiTypePackage::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}