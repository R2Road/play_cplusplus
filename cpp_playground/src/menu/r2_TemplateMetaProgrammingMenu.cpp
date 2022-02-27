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
	MenuUp TemplateMetaProgrammingMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, "Template Meta Programming" ) );

		{
			ret->AddChild( '1', template_meta_programming_test::CalculateFactorial::GetInstance() );
			ret->AddChild( '2', template_meta_programming_test::GreatestCommonDivisor::GetInstance() );
			ret->AddChild( '3', template_meta_programming_test::BasicRatio::GetInstance() );
			ret->AddChild( '4', template_meta_programming_test::SumBasicRatio::GetInstance() );
			ret->AddChild( '5', template_meta_programming_test::RatioWithGCD::GetInstance() );
			ret->AddChild( '6', template_meta_programming_test::SumRatioWithGCD::GetInstance() );
			ret->AddChild( '7', template_meta_programming_test::SumRatioAndOperator1::GetInstance() );
			ret->AddChild( '8', template_meta_programming_test::SumRatioAndOperator2::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'q', template_meta_programming_test::Character2String::GetInstance() );
			ret->AddChild( 'w', template_meta_programming_test::Integer2String::GetInstance() );
			ret->AddChild( 'e', template_meta_programming_test::CalculatePlaceValue::GetInstance() );
			ret->AddChild( 'r', template_meta_programming_test::Integer2String_II::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild( 'a', template_meta_programming_test::MultiTypePackage::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::TemplateMenu::Create( director ) );
					return r2::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}