#include "pch.h"
#include "r2_TemplateMetaProgrammingScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_TemplateScene.h"

#include "template_meta_programming_01_test.h"
#include "template_meta_programming_02_test.h"
#include "template_meta_programming_03_test.h"

namespace r2
{
	SceneUp TemplateMetaProgrammingScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Template Meta Programming" ) );

		{
			ret->AddChild( '1', template_meta_programming_test::CalculateFactorial::GetInstance() );
			ret->AddChild( '2', template_meta_programming_test::GreatestCommonDivisor::GetInstance() );
			ret->AddChild( '3', template_meta_programming_test::RatioBasic::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'q', template_meta_programming_test::Character2String::GetInstance() );
			ret->AddChild( 'w', template_meta_programming_test::Integer2String::GetInstance() );
			ret->AddChild( 'e', template_meta_programming_test::CalculatePlaceValue::GetInstance() );
			ret->AddChild( 'r', template_meta_programming_test::Integer2String_II::GetInstance() );


			ret->AddSplit();


			ret->AddChild( 'a', template_meta_programming_test::MultiTypePackage::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::TemplateScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}