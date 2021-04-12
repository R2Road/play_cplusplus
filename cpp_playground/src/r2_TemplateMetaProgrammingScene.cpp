#include "pch.h"
#include "r2_TemplateMetaProgrammingScene.h"

#include "r2_Director.h"
#include "r2_eTestResult.h"
#include "r2_RootScene.h"

#include "template_meta_programming_test.h"

namespace r2
{
	SceneUp TemplateMetaProgrammingScene::Create( Director& director )
	{
		SceneUp ret( new ( std::nothrow ) Scene( director, "Template Meta Programming" ) );

		{
			ret->AddChild( '1', template_meta_programming_test::CalculateFactorial::GetInstance() );
			ret->AddChild( '2', template_meta_programming_test::Character2String::GetInstance() );
			ret->AddChild( '3', template_meta_programming_test::Integer2String::GetInstance() );
			ret->AddChild( '4', template_meta_programming_test::CalculatePlaceValue::GetInstance() );
			ret->AddChild( '5', template_meta_programming_test::Integer2String_II::GetInstance() );
			ret->AddChild( '6', template_meta_programming_test::MultiTypePackage::GetInstance() );

			ret->AddChild(
				27
				, []()->const char* { return "\nESC : Return To Root"; }
				, [&director]()->const eTestResult
				{
					director.Setup( r2::RootScene::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}